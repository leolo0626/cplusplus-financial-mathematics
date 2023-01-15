#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"

class CallOption {
public:
    CallOption();
    double strike;
    double maturity;

    double payoff( double stockAtMaturity ) const;

    double price( const BlackScholesModel& bsm )
        const;
};

void testCallOption();