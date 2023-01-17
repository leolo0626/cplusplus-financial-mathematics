#pragma once
#include "BlackScholesModel.h"

class PutOption {
    public:
        double strike;
        double maturity;
        PutOption();
        PutOption(double strike, double maturity);
        double payoff (double stockAtMaturity);
        double price (BlackScholesModel &bsm);
};