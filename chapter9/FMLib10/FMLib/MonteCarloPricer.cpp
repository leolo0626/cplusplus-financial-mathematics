#include "MonteCarloPricer.h"

#include "matlib.h"
#include "CallOption.h"
#include "PutOption.h"
using namespace std;

MonteCarloPricer::MonteCarloPricer() :
    nScenarios(10000) {
}

double MonteCarloPricer::price(
        const PathIndependentOption& option,
        const BlackScholesModel& model ) {
    double total = 0.0;
    for (int i=0; i<nScenarios; i++) {
        vector<double> path= model.
            generateRiskNeutralPricePath(
                option.getMaturity(),
                1 );
        double stockPrice = path.back();
        double payoff = option.payoff( stockPrice );
        total+= payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = option.getMaturity() - model.date;
    return exp(-r*T)*mean;
}

//////////////////////////////////////
//
//   Tests
//
//////////////////////////////////////

static void testPriceCallOption() {
    rng("default");

    CallOption c;
    c.strike = 110;
    c.maturity = 2;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price( c, m );
    double expected = c.price( m );
    ASSERT_APPROX_EQUAL( price, expected, 0.1 );
}

static void testPutAndCall() {
	rng("default");

	BlackScholesModel m;
	m.volatility = 0.1;
	m.riskFreeRate = 0.05;
	m.stockPrice = 100.0;
	m.drift = 0.1;

	CallOption c;
	c.strike = 110;
	c.maturity = 2;

	PutOption p;
	p.strike = c.strike;
	p.maturity = c.maturity;

	// our pricer can price puts and calls
	MonteCarloPricer pricer;
	double priceC = pricer.price(c, m);
	ASSERT_APPROX_EQUAL(priceC, c.price(m), 0.1);
	double priceP = pricer.price(p, m);
	ASSERT_APPROX_EQUAL(priceP, p.price(m), 0.1);
}

void testMonteCarloPricer() {
    testPriceCallOption();
	testPutAndCall();
}