#pragma once

#include "stdafx.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesModel.h"
#include "UpAndOutOption.h"


class MonteCarloPricer {
public:
    /*  Constructor */
    MonteCarloPricer();
    /*  Number of scenarios */
    int nScenarios;
    /*  Price a call option */
    double price( const CallOption& option,
                  const BlackScholesModel& model );
    /* Price a put option */
    double price( const PutOption& option, 
                  const BlackScholesModel& model);

    double price ( const UpAndOutOption& option, const BlackScholesModel& model);
};

void testMonteCarloPricer();

