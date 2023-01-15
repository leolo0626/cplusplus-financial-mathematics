// #include "FMLib6/FMLib/testing.h"
#include "FMLib6/FMLib/matlib.h"

double max (double a, double b) {
    INFO("max(" << a << ", " << b << ")");
    return a > b ? a : b;
}

int main() {
    // setDebugEnabled(true);
    testMatlib();
    return 1;
}

