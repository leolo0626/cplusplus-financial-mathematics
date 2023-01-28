#pragma once
class PathIndependentOption {
    public:
        virtual ~PathIndependentOption() {};
        virtual double payoff(double finalStockPrice) const = 0 ;
        virtual double getMaturity() const = 0;
};