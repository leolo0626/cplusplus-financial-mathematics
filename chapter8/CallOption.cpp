#include <iostream>
#include "CallOption.h"
#include <cmath>
#include "FMLib8/FMLib/matlib.h"

CallOption::CallOption():
    strike(0.0),
    maturity(0.0) {};

CallOption::CallOption(double s, double m):
    strike(s),
    maturity(m){};

double CallOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity > strike) {
        return stockAtMaturity - strike; 
    } else {
        return 0.0;
    }
}

double CallOption::price(BlackScholesModel &bsm) {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log (S/K) + (r+sigma*sigma*0.5) * T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator / denominator;
    double d2 = d1 - denominator;
    return S * normcdf(d1) - K * exp(-r*T) * normcdf(d2);
}