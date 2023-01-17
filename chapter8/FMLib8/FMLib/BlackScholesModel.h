#pragma once

#include "stdafx.h"

class BlackScholesModel {
public:
    double stockPrice;
    double volatility;
    double riskFreeRate;
    double date;
};



void testBlackScholesModel();