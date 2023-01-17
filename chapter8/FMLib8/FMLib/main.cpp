#include "matlib.h"
#include "geometry.h"
#include "CallOption.h"
#include "PieChart.h"
#include "BlackScholesModel.h"

using namespace std;

int main() {
    testMatlib();
    testGeometry();
    testPieChart();
    testCallOption();
    testBlackScholesModel();
}