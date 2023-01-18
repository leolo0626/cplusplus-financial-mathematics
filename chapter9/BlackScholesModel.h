#pragma once
#include<iostream>
#include<vector>

class BlackScholesModel {
    public:
        double stockPrice;
        double volatility;
        double riskFreeRate;
        double date;
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