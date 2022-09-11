#include <iostream>
#include <cmath>
using namespace std; 


double integralWithRectangleRule(double (*func)(double), double start, double end, double n);

double functionToIntegrate(double x);

int main() {
    cout << "Integral with rectangle rule sin(x) " << integralWithRectangleRule(&sin, 0, M_PI, 1000) << "\n";
    return 0; 
}

double functionToIntegrate(double x) {
    // cout << "Process " << x << "\n";
    return x; 
}

double integralWithRectangleRule(double (*func)(double), double start, double end, double n) {
    double h = (end - start) / n ;
    double sumValue = 0;
    
    for (int i = 0; i < n; i++) {
        double params = start + i * h + 0.5 * h;
        sumValue += func(params);
    }
    return sumValue*h;
}