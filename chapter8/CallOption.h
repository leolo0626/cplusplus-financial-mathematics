#pragma once

class CallOption {
    public:
        double strike;
        double maturity;
        CallOption();
        CallOption(double strike, double maturity);
};