#include "MonteCarloPricer.h"

#include "../FMLib9/FMLib/matlib.h"

using namespace std;

MonteCarloPricer::MonteCarloPricer(): 
    nScenarios(1000) {

    }

double MonteCarloPricer::price(const CallOption &option, const BlackScholesModel &model) {
    double total = 0.0;
    for (int i = 0; i < nScenarios; i ++) {
        vector<double> path = model.generateRiskNeutralPricePath(
            option.maturity, 1
        );
        double stockPrice = path.back();
        double payoff = option.payoff(stockPrice);
        total += payoff;
    }
    double mean  = total / nScenarios;
    double r = model.riskFreeRate;
    double T = option.maturity - model.date;
    return exp(-r*T) * mean;
}

double MonteCarloPricer::price(const PutOption &option, const BlackScholesModel &model) {
    double total = 0.0;
    for (int i = 0; i < nScenarios; i ++) {
        vector<double> path = model.generateRiskNeutralPricePath(
            option.maturity, 1
        );
        double stockPrice = path.back();
        double payoff = option.payoff(stockPrice);
        total += payoff;
    }
    double mean  = total / nScenarios;
    double r = model.riskFreeRate;
    double T = option.maturity - model.date;
    return exp(-r*T) * mean;
}

double MonteCarloPricer::price(const UpAndOutOption &option, const BlackScholesModel &model) {
    double total = 0.0;
    for (int i = 0; i < nScenarios; i ++) {
        vector<double> path = model.generateRiskNeutralPricePath(
            option.maturity, 1
        );
        double payoff = option.computePayoff(path);
        total += payoff;
    }
    double mean  = total / nScenarios;
    double r = model.riskFreeRate;
    double T = option.maturity - model.date;
    return exp(-r*T) * mean;
}

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
    double price = pricer.price(c, m);
    double expected = c.price(m);
    ASSERT_APPROX_EQUAL(price, expected, 0.1);
}

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
    double price = pricer.price(p, m);
    double expected = p.price(m);
    ASSERT_APPROX_EQUAL(price, expected, 0.1);
}

static void testPriceUpAndOutOption() {
    rng("default");

    UpAndOutOption upAndOutOption;
    upAndOutOption.strike = 110;
    upAndOutOption.maturity = 2;
    upAndOutOption.barrier = 99999;

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
    double price = pricer.price(upAndOutOption, m);
    double expected = c.price(m);
    ASSERT_APPROX_EQUAL(price, expected, 0.1);
}


void testMonteCarloPricer() {
    TEST(testPriceCallOption);
    TEST(testPricePutOption);
    TEST(testPriceUpAndOutOption);
}