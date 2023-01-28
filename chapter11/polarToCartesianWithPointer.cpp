#include <cmath>
#include <iostream>

using namespace std;

void polarToCartesianWithPointer(double r, double theta, double* x, double* y);

int main() {
    double x ;
    double y ;
    polarToCartesianWithPointer(4, 30, &x, &y);
    cout << "x : " << x << '\n';
    cout << "y : " << y << '\n';
    return 0;
}

void polarToCartesianWithPointer(double r, double theta, double* x, double* y){
    *x = r * sin(theta);
    *y = r * cos(theta);
}