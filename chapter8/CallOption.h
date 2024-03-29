#pragma once
#include "BlackScholesModel.h"

class CallOption {
    public:
        double strike;
        double maturity;
        CallOption();
        CallOption(double strike, double maturity);
        double payoff (double stockAtMaturity) const;
        double price (BlackScholesModel &bsm);
};