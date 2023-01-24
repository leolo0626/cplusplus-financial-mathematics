#pragma once
#include "../model/BlackScholesModel.h"
#include "../FMLib9/FMLib/stdafx.h"

class UpAndOutOption {
    public:
        double strike;
        double barrier;
        double maturity;
        UpAndOutOption();
        UpAndOutOption(double k, double b, double t);
        double computePayoff(std::vector<double> &prices) const;
};