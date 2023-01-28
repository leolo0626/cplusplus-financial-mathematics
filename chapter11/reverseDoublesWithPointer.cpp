#include <iostream>

void reverseDoublesWithPointer(double* doubleList, int length);

int main() {
    double doubleList[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    reverseDoublesWithPointer(doubleList, 5);
    for(int i = 0 ; i < 5; i++) {
        std::cout << "doubleList[" << i << "] : " << doubleList[i] << "\n";
    }
    return 0;
}

void reverseDoublesWithPointer(double* doubleList, int length) {
    double* end = doubleList + length - 1;
    for (double* ptr = end; ptr > doubleList; ptr--) {
        double endValue = *ptr;
        *ptr =  *doubleList;
        *doubleList = endValue;
        doubleList++;
    }
}