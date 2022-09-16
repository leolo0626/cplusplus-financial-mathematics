#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"

class UpAndOutOption {
public:
    UpAndOutOption();
    double strike;
    double barrier;
    double maturity;

    double computePayoff(std::vector<double> stockPrices) const;
};

// void testUpAndOutOption();