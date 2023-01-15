# pragma once

#include "stdafx.h"
#include "PathIndependentOption.h"
#include "BlackScholesModel.h"

class DigitalCallOption: public PathIndependentOption {
    public:
        DigitalCallOption();
        double strike;
        double maturity;

        double payoff( double stockAtMaturity) const;
        double getMaturity() const;
};

void testDigitialCallOption();

