#include "PutOption.h"
#include "../FMLib9/FMLib/stdafx.h"
#include "../FMLib9/FMLib/matlib.h"


PutOption::PutOption(): 
    strike(0.0),
    maturity(0.0) {
};

PutOption::PutOption(double s, double m): 
    strike(s),
    maturity(s) {};

double PutOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity > strike) {
        return 0.0;
    } else {
        return strike - stockAtMaturity;
    }
};

double PutOption::price(BlackScholesModel &bsm) const {
    double S = bsm.stockPrice;
    double K = strike;
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = maturity - bsm.date;

    double numerator = log (S/K) + (r+sigma*sigma*0.5) * T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator / denominator;
    double d2 = d1 - denominator;
    return K * exp(-r*T) * normcdf(-d2) - S * normcdf(-d1);
};

double PutOption::getMaturity() const {
    return maturity;
}