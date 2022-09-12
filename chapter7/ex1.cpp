#include <iostream>
#include <cmath>
#include <vector>


int solveQuadratic(double a, double b, double c, double &x1, double&x2);
std::vector<double> solveQuadraticVectorVer(double a, double b, double c);

int main() {
    double x1;
    double x2;
    std::cout << "The number of root of x^2 + 2x + 1 is " << solveQuadratic(1, 2, 1, x1, x2) << "\n";
    std::cout << "The root is  " << x1 << " and  " << x2 << "\n";


    std::vector<double> myVector = solveQuadraticVectorVer(1, 2, 1);
    std::cout << "The number of root of x^2 + 2x + 1 is (Vector)" << myVector[0] << "\n";
    std::cout << "The root is  " << myVector[1] << " and  " << myVector[2] << "\n";
    return 0;
}

int solveQuadratic(double a, double b, double c, double &x1, double &x2) {
    double det = std::pow(b, 2) - 4 * a * c ;
    if (det >= 0) {
        double denominator = 2 * a * c;
        x1 = (-b + std::sqrt(det)) / denominator;
        x2 = (-b - std::sqrt(det)) / denominator;
        return det == 0 ? 1 : 2;
    }
    return 0;
}

std::vector<double> solveQuadraticVectorVer(double a, double b, double c) {
    std::vector<double> myResultVector(3, (double) NULL);
    std::cout << "my result vector " << myResultVector[0] << "\n";
    double det = std::pow(b, 2) - 4 * a * c ;
    myResultVector[0] = 0.0;
    if (det >= 0) {
        double denominator = 2 * a * c;
        myResultVector[0] = det == 0 ? 1 : 2;
        myResultVector[1] = (-b + std::sqrt(det)) / denominator;
        myResultVector[2] = (-b - std::sqrt(det)) / denominator;
        return myResultVector;
    }
    return myResultVector;
}