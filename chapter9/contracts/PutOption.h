#pragma once
#include "../model/BlackScholesModel.h"
#include "PathIndependentOption.h"

class PutOption: public PathIndependentOption {
    public:
        double strike;
        double maturity;
        PutOption();
        PutOption(double strike, double maturity);
        double payoff (double stockAtMaturity) const;
        double price (BlackScholesModel &bsm) const;
        double getMaturity() const;
};