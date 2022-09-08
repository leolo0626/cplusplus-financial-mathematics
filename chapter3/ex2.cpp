#include <iostream>
using namespace std;

void printBetween(int a, int b) {
    if (a > b) {
        return ;
    }
    cout << a ;
    printBetween(a+1, b);
}

int main() {
    printBetween(0, 10);
    return  0;
}