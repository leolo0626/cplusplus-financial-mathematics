#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int principal;
    double interestRate;
    int numberOfYears;

    cout << "How much are you investing? \n";
    cin >> principal;
    cout << "What's the annual interest rate (%)? \n";
    cin >> interestRate;
    cout << "How long for (years) ? \n";
    cin >> numberOfYears;

    double finalBalance = pow(1.0+interestRate*0.01, numberOfYears) * principal;
    double interest = finalBalance - principal;

    cout << "You will earn ";
    cout << interest;
    cout << "\n";

    return 0;
}
