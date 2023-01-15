#include "DigitalCallOption.h"
#include "matlib.h"

DigitalCallOption::DigitalCallOption():
    strike(0.0),
    maturity(0.0) {}

double DigitalCallOption::payoff(double stockAtMaturity) const {
    if (stockAtMaturity > strike) {
        return 1.0;
    }
    return 0.0;
}


double DigitalCallOption::getMaturity() const {
    return maturity;
}