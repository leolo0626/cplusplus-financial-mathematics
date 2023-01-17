#include "CallOption.h"
#include "PutOption.h"
#include "FMLib8/FMLib/testing.h"
#include "BlackScholesModel.h"

static void testCallOptionPrice();
static void testPutOptionPrice();

int main () {
    setDebugEnabled(true);
    TEST (testCallOptionPrice);
    TEST (testPutOptionPrice);
    return 1;
}


static void testCallOptionPrice() {
    CallOption callOption;
    callOption.strike = 105.0;
    callOption.maturity = 2.0;

    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = callOption.price(bsm);
    ASSERT_APPROX_EQUAL(price, 4.046, 0.01);
}

static void testPutOptionPrice() {
    PutOption putOption;
    putOption.strike = 105.0;
    putOption.maturity = 2.0;

    BlackScholesModel bsm;
    bsm.date = 1.0;
    bsm.volatility = 0.1;
    bsm.riskFreeRate = 0.05;
    bsm.stockPrice = 100.0;

    double price = putOption.price(bsm);
    ASSERT_APPROX_EQUAL(price, 3.92, 0.01);
}


