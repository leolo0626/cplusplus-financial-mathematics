#pragma once

class BlackScholesModel {
    public:
        double stockPrice;
        double data;
        double volatility;
        double riskFreeRate;
        BlackScholesModel();
        BlackScholesModel(double stockPrice);
};  