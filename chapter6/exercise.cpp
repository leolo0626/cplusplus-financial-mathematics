#include "FMLib6/FMLib/testing.h"
#include "FMLib6/FMLib/matlib.h"
#include <cmath>

double computeArea(double r);

double computeCircumference(double r);

double bsm(double spot, double strike, double r, double vol, double t, bool isCall);

void testArea();

void testCircumference();

void testBSM();


int main() {
    setDebugEnabled(false);
    TEST( testArea );
    TEST( testCircumference );
    TEST( testBSM );
    return 1;
}

double computeArea(double r) {
    DEBUG_PRINT("Area of circle with radius " << r);
    return PI * r * r;
};

double computeCircumference(double r) {
    return 2 * PI * r;
};

double bsm(double spot, double strike, double r, double vol, double t, bool isCall = true) {
    double d1 = 1 / (vol * sqrt(t)) * (log( spot / strike ) + ( r + vol * vol / 2 ) * t);
    double d2 = d1 - (vol * sqrt(t));

    if (isCall) {
        return spot * normcdf(d1) - strike * exp(-r*t) * normcdf(d2);
    } 
    return strike * exp(-r*t) * normcdf(-d2) -  spot * normcdf(-d1) ;
};

void testArea() {
    ASSERT_APPROX_EQUAL(computeArea(10), 314.159, 0.001);
};

void testCircumference() {
    ASSERT_APPROX_EQUAL(computeCircumference(10), 62.832, 0.001);
};

void testBSM() {
    ASSERT_APPROX_EQUAL(bsm(300, 250, 0.03, 0.15, 1, false), 1.43, 0.01);
};