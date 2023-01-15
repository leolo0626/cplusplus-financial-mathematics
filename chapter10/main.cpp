#include "matlib.h"
#include "textfunctions.h"
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"

using namespace std;

int main() {
    testMonteCarloPricer();
    testBlackScholesModel();
    testMatlib();
    return 0;
}