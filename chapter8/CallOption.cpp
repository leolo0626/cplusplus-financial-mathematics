#include <iostream>
#include "CallOption.h"

CallOption::CallOption():
    strike(0.0),
    maturity(0.0) {};

CallOption::CallOption(double s, double m):
    strike(s),
    maturity(m){};

