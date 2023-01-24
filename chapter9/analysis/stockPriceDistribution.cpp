#include "../model/BlackScholesModel.h"
#include "../FMLib9/FMLib/stdafx.h"
#include "../FMLib9/FMLib/Histogram.h"

using namespace std;

int main() {
    BlackScholesModel bsm;

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    int nScenarios = 1000;
    vector<double> result(nScenarios, 0.0);

    for (int i =0 ; i < nScenarios; i++) {
        vector<double> path = m.generateRiskNeutralPricePath(
            2, 1
        );

        double stockPrice = path.back();
        result[i] = stockPrice;
    }

    Histogram histogramChart;
    histogramChart.setNumBuckets(100);
    histogramChart.setTitle("Distribution of Stock Price");
    histogramChart.setData(result);
    histogramChart.writeAsHTML("distribution.html");
    return 0;
}