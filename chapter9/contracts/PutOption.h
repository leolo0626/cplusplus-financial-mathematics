#pragma once
#include "../model/BlackScholesModel.h"

class PutOption {
    public:
        double strike;
        double maturity;
        PutOption();
        PutOption(double strike, double maturity);
        double payoff (double stockAtMaturity) const;
        double price (BlackScholesModel &bsm) const;
};