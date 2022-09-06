#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = -1;
    unsigned int b = 0;
    if ( a < b) {
        cout << "a is smaller \n";
    } else {
        cout << "a is bigger \n";
    }
    unsigned int castValue = (unsigned int ) a;
    cout << castValue; 

    return 0;
}