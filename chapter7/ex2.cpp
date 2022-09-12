#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <random>
#include "../chapter6/FMLib6/FMLib/matlib.h"
#include <algorithm>

double mean(std::vector<double> arr); 
double standardDeviation(std::vector<double> arr, bool isPopulation = false);
double min(std::vector<double> arr);
double max (std::vector<double> arr);
std::vector<double> randuniform(int n);
std::vector<double> randn(int n);
std::vector<double> randn_BoxMullerMethod(int n);
void normalVar_BoxMullerMethod(double &z1, double &z2);
void testSortVector(std::vector<double> &v1);

int main() {
    std::vector<double> vect = { 5.0, 8.0, 9.0 ,10.0, 12.0, 13.0};
    std::cout << " The mean is " << mean(vect) << "\n" ;
    std::cout << " The population std is " << standardDeviation(vect, true) << "\n";
    std::cout << " The sample std is " << standardDeviation(vect) << "\n";
    std::cout << " The min value is " << min(vect) << "\n";
    std::cout << " The max value is " << max(vect) << "\n";
    std::vector<double> uniVector = randuniform(100);
    std::cout << " The size of uniform random vector is " << uniVector.size() <<  "\n";
    std::cout << " The first element of the uniform random vector is " << uniVector[0] << '\n';
    std::vector<double> normalVector = randn(100);
    std::cout << " The size of normal random vector is " << normalVector.size() << "\n";
    std::cout << " The first element of the normal random vector is " <<  normalVector[0] << "\n";
    std::vector<double> unsortedVector({ 5.0, 1.0, 2.0, 3.0, 0.0, 12.0, 9.0});
    testSortVector(unsortedVector);
    return 0; 
}

double mean(std::vector<double> arr) {
    int n = arr.size();
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total/n;
}

double standardDeviation(std::vector<double> arr, bool isPopulation) {
    double average = mean(arr);
    int n = arr.size();
    double sqSum = 0.0;
    for (int i=0; i < n ; i++) {
        sqSum += std::pow((arr[i]-average), 2);
    }
    if (isPopulation) {
        return 1.0* std::sqrt(sqSum/n);
    }
    return 1 *std::sqrt(sqSum/(n-1));
}

double min(std::vector<double> arr) {
    double minVal = arr[0];
    for (int i = 1;  i < arr.size() ; i++ ){
        if (minVal > arr[i] ) {
            minVal = arr[i];
        }
    }
    return minVal;
}

double max(std::vector<double> arr) {
    double maxVal = arr[0];
    for (int i = 1; i< arr.size();  i++ ) {
        if (maxVal < arr[i]) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


std::vector<double> randuniform(int n) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    std::vector<double> uniVector(n, 0.0);
 
    for (int i=0; i<n; i++) {
        double randomVariable = distribution(generator) ;
        uniVector[i] = randomVariable;
    }

    return uniVector;
}

std::vector<double> randn(int n) {
    // By using inverse transform,
    std::vector<double> normalVector = randuniform(n);
    for (int i=0; i<n; i++) {
        normalVector[i]= norminv(normalVector[i]) ;
    }
    return normalVector;
}

std::vector<double> randn_BoxMullerMethod(int n) {
    std::vector<double> normalVector = randuniform(n);
    for (int i=0; i<n; i++) {
        std::cout << "Before " << normalVector[i] << " " ;
        double z2 = 0.0;
        normalVar_BoxMullerMethod(normalVector[i], z2);
        std::cout << "After " << normalVector[i] << "\n" ;
    }
    return normalVector;
}

void normalVar_BoxMullerMethod(double &z1, double &z2) {
    z1 = std::sqrt(-2 * std::log(z1)) * std::cos(2* M_PI * z1);
    z2 = std::sqrt(-2 * std::log(z2)) * std::cos(2* M_PI * z2);
}

void testSortVector(std::vector<double> &v1) {
    std::sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        std::cout << "Vector[" << i << "] is " <<  v1[i] << "\n";
    }
}