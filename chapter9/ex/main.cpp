#include "matlib.h"
#include "geometry.h"
#include "textfunctions.h"
#include "CallOption.h"
#include "PutOption.h"
#include "PieChart.h"
#include "LineChart.h"
#include "BlackScholesModel.h"
#include "Histogram.h"
#include "MonteCarloPricer.h"

using namespace std;

int main() {
    testCallOption();
    testPutOption();
    testMonteCarloPricer();
    testBlackScholesModel();
    return 0;
}