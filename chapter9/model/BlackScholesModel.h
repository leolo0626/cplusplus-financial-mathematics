#pragma once
#include "../FMLib9/FMLib/stdafx.h"

class BlackScholesModel {
    public:
        double stockPrice;
        double volatility;
        double riskFreeRate;
        double date;
        double drift;
        BlackScholesModel();
        std::vector<double> generatePricePath(
            double toDate,
            int nSteps
        ) const;

        std::vector<double> generateRiskNeutralPricePath(
            double toDate,
            int nSteps
        ) const;

    private:
        std::vector<double> generatePricePath(
            double toDate,
            int nSteps,
            double drift
        ) const;

};

void testBlackScholesModel();