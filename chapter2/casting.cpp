#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double x = 3.43;
    int xAsInt = (int) x; //C-Style Cast
    int xAsInt_inCplusplusStyle = static_cast<int>(x); 
    cout << "(int) x: " << xAsInt << "\n" ; // xAsInt = 3;
    cout << "(int) x C++: " << xAsInt_inCplusplusStyle << "\n" ; // xAsInt = 3;

    int a = 3;
    int b = 5;
    double c = a / b;
    cout << "c : " << c << "\n" ; // c = 0;

    double c_2 = (double) (a / b);
    cout << "c2 : " << c_2 << "\n" ; // c_2 = 0;

    // correct way to get answer
    double fraction = ((double) a)/ b; // fraction = 0.6;

    cout << "Fraction : " << fraction << "\n";
    return 0;
}

