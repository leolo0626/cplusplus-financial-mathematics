#include "../FMLib9/FMLib/matlib.h"
#include "../FMLib9/FMLib/LineChart.h"
#include "BlackScholesModel.h"

using namespace std;

BlackScholesModel::BlackScholesModel() :
    stockPrice(0.0),
    volatility(0.0),
    riskFreeRate(0.0),
    date(0.0) {
}

vector<double> BlackScholesModel::generatePricePath(
    double toDate,
    int nSteps,
    double drift
) const {
    vector<double> path(nSteps, 0.0);
    vector<double> epsilon = randn(nSteps);
    double dt = (toDate - date) / nSteps;
    double a = (drift - volatility * volatility * 0.5) * dt;
    double b  = volatility * sqrt(dt);
    double currentLogS = log( stockPrice );
    for (int i = 0; i < nSteps ; i++) {
        double dLogS = a + b * epsilon[i];
        double logS = currentLogS + dLogS;
        path[i] = exp( logS );
        currentLogS = logS;
    }
    return path;
};

vector<double> BlackScholesModel::generatePricePath(
    double toDate,
    int nSteps
) const {
    return generatePricePath(toDate, nSteps, drift);
};

vector<double> BlackScholesModel::generateRiskNeutralPricePath(
    double toDate,
    int nSteps
) const {
    return generatePricePath(toDate, nSteps, riskFreeRate);
};

static void testVisually() {
    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;

    int nSteps = 1000;
    double maturity = 4.0;

    vector<double> path =
	    bsm.generateRiskNeutralPricePath( maturity, nSteps );
    double dt = (maturity-bsm.date)/nSteps;
    vector<double> times =
        linspace(dt,maturity,nSteps);
	LineChart lineChart;
	lineChart.setTitle("Stock price path");
	lineChart.setSeries(times, path);
	lineChart.writeAsHTML("examplePricePath.html");
};


static void testRiskNeutralPricePath() {
    rng("default");

    BlackScholesModel bsm;
    bsm.riskFreeRate = 0.05;
    bsm.volatility = 0.1;
    bsm.stockPrice = 100.0;
    bsm.date = 2.0;

    int nPaths = 10000;
    int nsteps = 5;
    double maturity = 4.0;
    vector<double> finalPrices(nPaths,0.0);
    for (int i=0; i<nPaths; i++) {
        vector<double> path =
            bsm.generateRiskNeutralPricePath(
	            maturity, nsteps );
        finalPrices[i] = path.back();
    }

    ASSERT_APPROX_EQUAL( mean( finalPrices ),
        exp( bsm.riskFreeRate*2.0)*bsm.stockPrice,
             0.5);
};


void testBlackScholesModel() {
    TEST( testVisually );
    TEST( testRiskNeutralPricePath );
};
