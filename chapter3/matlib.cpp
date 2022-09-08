#include <iostream>
#include <cmath>
#include <stdexcept>
#include <sstream>
using namespace std;


double normcdf_complex(double x) {
    if ( x < 0 ) {
        return 1 - normcdf_complex(-x);
    }
    double k = 1/(1+0.2316419 * x);
    return 1 - 1/sqrt(2* M_PI) * exp(-pow(x, 2)/2) * k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k*(-1.821255978 + 1.330274429 * k))));
}

double normcdf(double x);
double norminv(double x);
double blackScholesCallPrice(double spot, double strike, double time, double vol, double rfRate);

double hornerFunc (double x, double a0) {
    return a0;
}

double hornerFunc(double x, double a0, double a1) {
    return a0 + x * hornerFunc(x, a1);
}

double hornerFunc(double x, double a0, double a1, double a2) {
    return a0 + x * hornerFunc(x, a1, a2);
}

double hornerFunc(double x, double a0, double a1, double a2, double a3) {
    return a0 + x * hornerFunc(x, a1, a2, a3);
}

double hornerFunc(double x, double a0, double a1, double a2, double a3, double a4) {
    return a0 + x * hornerFunc(x, a1, a2, a3, a4);
}

double hornerFunc(double x, double a0, double a1, double a2, double a3, double a4, double a5) {
    return a0 + x * hornerFunc(x, a1, a2, a3, a4, a5);
}

double hornerFunc(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6) {
    return a0 + x * hornerFunc(x, a1, a2, a3, a4, a5, a6);
}

double hornerFunc(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7) {
    return a0 + x * hornerFunc(x, a1, a2, a3, a4, a5, a6, a7);
}

double hornerFunc(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8) {
    return a0 + x * hornerFunc(x, a1, a2, a3, a4, a5, a6, a7, a8);
}

int main() {
    cout << "normcdf(1.96) " << normcdf(1.96) << "\n";
    cout << "norminv(0.975 " << norminv(0.975) << "\n";
    cout << "blackScholesModel(300, 250, 1, 0.15, 0.03) "<< blackScholesCallPrice(300, 250, 1, 0.15, 0.03) << "\n";
    return 0 ;
}


double normcdf(double x) {
    return 0.5 * erfc(-x * M_SQRT1_2);
}

double norminv(double p) {
    double a0 = 2.50662823884;
    double a1 = -18.61500062529;
    double a2 = 41.39119773534;
    double a3 = -25.44106049637;
    double b1 = -8.47351093090;
    double b2 = 23.08336743743;
    double b3 = -21.06224101826;
    double b4 = 3.13082909833;
    double c0 = 0.3374754822726147;
    double c1 = 0.9761690190917186;
    double c2 = 0.1607979714918209;
    double c3 = 0.0276438810333863;
    double c4 = 0.0038405729373609;
    double c5 = 0.0003951896511919;
    double c6 = 0.0000321767881768;
    double c7 = 0.0000002888167364;
    double c8 = 0.0000003960315187;

    if ( p < 0 && p > 1) {
        stringstream os ;
        os << "Invalid input argument (" << p << "); must be larger than 0 but less 1";
        throw invalid_argument(os.str());
    }

    double y = p - 0.5; 
    double r ;
    if (abs(y) < 0.42) {
        r = pow(y, 2);
        return y * hornerFunc(r, a0, a1, a2, a3)/hornerFunc(r, 1.0, b1, b2, b3, b4);
    } 
    r = y < 0 ? p : 1 - p;
    double s = log(-log(r));
    double t = hornerFunc(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);

    if (p > 0.5) {
        return t;
    }

    return -t;
    
}

double blackScholesCallPrice(double spot, double strike, double time, double vol, double rfRate) {
    double numerator = log(spot/strike) + (rfRate + pow(vol, 2) * time);
    double denominator = vol * sqrt(time);
    double d1 = numerator / denominator;
    double d2 = d1 - vol * sqrt(time);
    double t1 = normcdf(d1) * spot;
    double t2 = strike * exp ( -rfRate * time ) * normcdf(d2);
    return t1 - t2;
}