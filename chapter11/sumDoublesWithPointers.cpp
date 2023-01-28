#include <iostream>

double sumDoublesWithPointer(double* toSum, int length);

int main() {
    double doubleList[3] = {1.0, 2.0, 3.1};
    std::cout << "Sum Double with pointer: " << sumDoublesWithPointer(doubleList, 3) << "\n";
};

double sumDoublesWithPointer(double* toSum, int length) {
    double sum = 0.0 ;
    double* end = toSum + length;
    for(double* ptr=toSum; ptr < end; ptr++){
        sum += *ptr;
    }
    return sum;
}