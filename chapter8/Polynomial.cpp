#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

class Polynomial {
    public:
        std::vector<double> coefficients;
        double evaluate(double x);
        Polynomial();
        Polynomial(std::vector<double> v1);
        Polynomial(double c);
        void add(const Polynomial &otherP);
        std::string toString();
};

Polynomial::Polynomial():
    coefficients(std::vector<double>({0.0})) {} ;

Polynomial::Polynomial(double c):
    coefficients(std::vector<double>({c})) {};

Polynomial::Polynomial(std::vector<double> v1):
    coefficients(v1) {};

double Polynomial::evaluate(double x) {
    double total = 0.0;
    for (int i = 0; i < coefficients.size(); i++) {
        total += std::pow(x, i) * coefficients[i];
    }
    return total;
};

void Polynomial::add(const Polynomial &otherP) {
    int n1 = coefficients.size();
    int n2 = otherP.coefficients.size();
    if (n1 >= n2) {
        for (int i = 0; i < n1; i++) {
            coefficients[i] += otherP.coefficients[i];
        }
    }

    for (int i=0; i < n1; i++) {
        coefficients[i] += otherP.coefficients[i];
    }

    for (int i=n1; i < n2; i++) {
        coefficients.push_back(otherP.coefficients[i]);
    }
}

std::string Polynomial::toString() {
    std::stringstream ss;
    for (int i=0; i< coefficients.size(); i++) {
        ss << coefficients[i];
        ss << "x^";
        ss << i;
        if (i != coefficients.size()-1) {
            ss << "+";
        }
    }
    return ss.str();
}

int main() {
    Polynomial p1(std::vector<double>({1.0, 2.0, 3.0}));
    std::cout << p1.toString() << "\n";
    std::cout << "Evaluate the polynomial with x = 10 " << p1.evaluate(10) << "\n";
    Polynomial p2(std::vector<double>({1.0, 2.0, 3.0, 4.0}));
    std::cout << p2.toString() << "\n";
    p1.add(p2);
    std::cout << "P1 add P2 " << p1.toString() << "\n";
    return 0;
}
