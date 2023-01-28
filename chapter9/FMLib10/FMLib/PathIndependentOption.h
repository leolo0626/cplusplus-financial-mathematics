`#pragma once

#include "stdafx.h"

/**
 *   This states that all path independent options
 *   have a payoff determined by the final stock price
 */
class PathIndependentOption {
public:
    /*  A virtual destructor */
    virtual ~PathIndependentOption() {}
    /*  Returns the payoff at maturity */
    virtual double payoff(
	    double finalStockPrice) const = 0;
    /*  Returns the maturity of the option */
    virtual double getMaturity() const
        = 0;
};