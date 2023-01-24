#pragma once

#include "../FMLib9/FMLib/stdafx.h"
#include "../contracts/CallOption.h"
#include "../contracts/PutOption.h"
#include "../contracts/UpAndOutOption.h"
#include "../model/BlackScholesModel.h"


class MonteCarloPricer {
    public :
        MonteCarloPricer();
        int nScenarios;
        double price(const CallOption &option, const BlackScholesModel &bsm);  
        double price(const PutOption &option, const BlackScholesModel &bsm);
        double price(const UpAndOutOption &option, const BlackScholesModel &bsm);
};

void testMonteCarloPricer();
