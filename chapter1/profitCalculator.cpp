#include <iostream>
using namespace std;

int main() {
    float revenue;
    float cost;
    float grossProfit;
    float netProfit;
    float tax;
    cout << "Please input revenue; \n";
    cin >> revenue;
    cout << "Please input cost; \n";
    cin >> cost;
    grossProfit = revenue - cost;
    cout << "Our Gross Profit is $ " << grossProfit << "\n" ;
    cout << "Please input Tax(%); \n";
    cin >> tax;
    if (grossProfit <= 0) {
        netProfit = grossProfit;
    } else {
        netProfit = grossProfit * ( 1 - tax / 100);
    }
    cout << "Our Net Profit is $ " << netProfit << "\n" ;

    return 0;
}