#include "PutOption.h"

#include "matlib.h"


PutOption::PutOption() :
  strike(0.0),
  maturity(0.0) {
}

double PutOption::payoff( double stockAtMaturity ) const {
    if (stockAtMaturity<strike) {
        return strike - stockAtMaturity;
    } else {
        return 0.0;
    }
}

double PutOption::price( 
        const BlackScholesModel& bsm ) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log( S/K ) + ( r + sigma*sigma*0.5)*T;
    double denominator = sigma * sqrt(T );
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return exp(-r*T)*K*normcdf(-d2) - S*normcdf(-d1);
}




//////////////////////////
//
//  Test the call option class
//  
//
//////////////////////////

static void testPutOptionPrice() {
    PutOption putOption;
    putOption.strike = 105.0;
    putOption.maturity = 2.0;
    
    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = putOption.price( bsm );  
    std::cout << "Price : " << price << "\n";
    std::cout << "Put call parity " << 4.046 - 100 + 105 * exp(-bsm.riskFreeRate * (putOption.maturity-bsm.date)) << "\n";
    ASSERT_APPROX_EQUAL( price, 4.046 + 100 + 105 * exp(-bsm.riskFreeRate * (putOption.maturity-bsm.date)) , 0.01);
}

void testPutOption() {
    TEST( testPutOptionPrice );
}
