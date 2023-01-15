#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 6;
    
    int c = b * (a+=3);

    cout << "a : " << a << " b: " << b << " c: " << c << "\n";

    int d = 3;
    int e = ++d;
    cout << "d : " << d  << " e : " << e << "\n ";

    int f = 3;
    int g = f++;
    cout << "f: " << f << " g: " << g << "\n";
}