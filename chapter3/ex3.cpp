#include <iostream>
using namespace std;

int fib (int n) {
    if (n <= 1) {
        return 1;
    }
    return fib(n-2) + fib(n-1);
}

int main() {
    cout << fib(8);
    return 0; 
}