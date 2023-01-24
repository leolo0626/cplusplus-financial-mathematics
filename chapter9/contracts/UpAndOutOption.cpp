#include "UpAndOutOption.h"

UpAndOutOption::UpAndOutOption(): 
    strike(0.0),
    barrier(0.0),
    maturity(0.0) {};

UpAndOutOption::UpAndOutOption(double k, double b, double t):
    strike(k),
    barrier(b),
    maturity(t) {};

double UpAndOutOption::computePayoff(std::vector<double> &prices) const {
    for (int i = 0; i < prices.size(); i++){
        if (prices[i] > barrier) {
            return 0.0;
        }
    }
    return std::max(prices.back() - strike, 0.0);
};