#include "MonteCarloPricer.h"

#include "matlib.h"

using namespace std;

MonteCarloPricer::MonteCarloPricer() :
    nScenarios(100000) {
}

double MonteCarloPricer::price(
        const CallOption& callOption,
        const BlackScholesModel& model ) {
    double total = 0.0;
    for (int i=0; i<nScenarios; i++) {
        vector<double> path= model.
                generateRiskNeutralPricePath(
                    callOption.maturity,
                    1 );
        double stockPrice = path.back();
        double payoff=callOption.payoff(stockPrice);
        total+= payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = callOption.maturity - model.date;
    return exp(-r*T)*mean;
}

double MonteCarloPricer::price(
    const PutOption& putOption,
    const BlackScholesModel& model ) {
    double total = 0.0;
    for (int i=0; i<nScenarios; i++) {
        vector<double> path= model.
                generateRiskNeutralPricePath(
                    putOption.maturity,
                    1 );
        double stockPrice = path.back();
        double payoff=putOption.payoff(stockPrice);
        total+= payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = putOption.maturity - model.date;
    return exp(-r*T)*mean;
}


double MonteCarloPricer::price(
    const UpAndOutOption& upAndOutOption,
    const BlackScholesModel& model) {
    double total = 0.0;
    for (int i=0; i<nScenarios; i++) {
        vector<double> path = model.
            generateRiskNeutralPricePath(
                upAndOutOption.maturity,
                1);
        double payoff = upAndOutOption.computePayoff(path);
        total+= payoff;
    }
    double mean = total/nScenarios;
    double r = model.riskFreeRate;
    double T = upAndOutOption.maturity - model.date;
    return exp(-r*T)*mean;
}
//////////////////////////////////////
//
//   Tests
//
//////////////////////////////////////

static void testPricePutOption() {
    rng("default");

    PutOption p;
    p.strike = 110;
    p.maturity = 2;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price( p, m );
    double expected = p.price( m );

    std::cout << "Monte Carlo Pricing [Actual] " << price << "\n";
    std::cout << "Monte Carlo Pricing [Expected] " << expected << "\n";

    ASSERT_APPROX_EQUAL( price, expected, 0.1 );
}

static void testPriceUpAndOutOption() {
    rng("default");

    UpAndOutOption option;
    option.strike = 80;
    option.barrier = 110;
    option.maturity = 2;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 75.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price( option, m );

    std::cout << "Monte Carlo Pricing [Actual] " << price << "\n";
    // std::cout << "Monte Carlo Pricing [Expected] " << expected << "\n";

    ASSERT_APPROX_EQUAL( price, expected, 0.1 );
}

static void testPriceCallOption() {
    rng("default");

    CallOption c;
    c.strike = 80;
    c.maturity = 2;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 75.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price( c, m );
    double expected = c.price( m );
    std::cout << "Monte Carlo Pricing [Actual] " << price << "\n";
    std::cout << "Monte Carlo Pricing [Expected] " << expected << "\n";

    ASSERT_APPROX_EQUAL( price, expected, 0.1 );
}

void testMonteCarloPricer() {
    testPriceCallOption();
    // testPricePutOption();
    testPriceUpAndOutOption();
}