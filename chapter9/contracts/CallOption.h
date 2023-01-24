#pragma once

#include "../FMLib9/FMLib/stdafx.h"
#include "../model/BlackScholesModel.h"

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