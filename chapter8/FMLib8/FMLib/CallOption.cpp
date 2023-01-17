#include "CallOption.h"

#include "matlib.h"

double CallOption::payoff(
		double stockAtMaturity ) const {
    if (stockAtMaturity>strike) {
        return stockAtMaturity-strike;
    } else {
        return 0.0;
    }
}
double CallOption::price( 
        const BlackScholesModel& bsm ) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator =
	    log( S/K ) + ( r + sigma*sigma*0.5)*T;
    double denominator = sigma * sqrt(T );
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return S*normcdf(d1) - exp(-r*T)*K*normcdf(d2);
}



//////////////////////////
//
//  Test the call option class
//  
//
//////////////////////////

static void testCallOptionPrice() {
    CallOption callOption;
    callOption.strike = 105.0;
    callOption.maturity = 2.0;
    
    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = callOption.price( bsm );
    ASSERT_APPROX_EQUAL( price, 4.046, 0.01);
}

void testCallOption() {
    TEST( testCallOptionPrice );
}
