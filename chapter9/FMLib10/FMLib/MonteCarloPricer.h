#pragma once

#include "stdafx.h"
#include "PathIndependentOption.h"
#include "BlackScholesModel.h"

class MonteCarloPricer {
public:
    /*  Constructor */
    MonteCarloPricer();
    /*  Number of scenarios */
    int nScenarios;
    /*  Price a call option */
    double price( const PathIndependentOption& option,
                  const BlackScholesModel& model );
};

void testMonteCarloPricer();

