#include "UpAndOutOption.h"

#include "matlib.h"


UpAndOutOption::UpAndOutOption():
    strike(0.0),
    maturity(0.0),
    barrier(0.0) {}
 
 double UpAndOutOption::computePayoff(std::vector<double> prices) const {
    for (int i = 0; i < prices.size() ; i++) {
        if (prices[i] >= barrier) {
            return 0.0;
        }
    }
    std::vector<double> vect{prices.back() - strike,0};
    return max(vect);
 }