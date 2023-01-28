#include <iostream>
#include <string>

class Pair{
    public:
        double x;
        double y;
        Pair();
        Pair(double x, double y);
};


int sumArray (int toSum[] , int length);

int sumUsingPointerAndPlusPlus(int* begin, int n);

void testSumUsingPointerAndPlusPlus();

int* testRetArray(int toSum[], int length);

void printArray(int n);

void accessFieldsOfAnObjectViaPointer();

void constPointerExamples();

char* thisFunctionReturnsAPointer(); //poor code

void someOtherFunction();

void testReturnPointerJustAboutOK();

int main() {
    int myArray[3] = {1, 2, 3};
    std::cout << "Sum of the array: " << sumArray(myArray, 3) << "\n";
    std::cout << "Return the array directly: " << testRetArray(myArray, 3) << "\n" ;
    printArray(5);
    accessFieldsOfAnObjectViaPointer();
    testSumUsingPointerAndPlusPlus();
    constPointerExamples();
    testReturnPointerJustAboutOK();
    return 1;
};

Pair::Pair(): 
    x(0.0),
    y(0.0) {};

Pair::Pair(double x, double y):
    x(x),
    y(y) {};

int sumArray(int toSum[], int length) {
    int total = 0 ;
    for (int i = 0; i < length; i++) {
        total += toSum[i];
    }
    return total;
};

int* testRetArray(int toSum[], int length) {
    return toSum;
};

void printArray(int n) {
    int* myArray = new int[n];
    for (int i = 0; i < n; i++) {
        std::cout<< "Entry i: " << i << "\n";
        std::cout<< "Myarray[" << i << "]: " << myArray[i] << "\n";
    }
    delete[] myArray;
};

void accessFieldsOfAnObjectViaPointer() {
    Pair p;
    Pair* pointToPairP = &p;

    pointToPairP->x = 123.0;
    pointToPairP->y = 234.0;

    std::cout << "p.x: " << p.x << "\n";
    std::cout << "p.y: " << p.y << "\n";

    std::cout << "(*pointToPairP).x: " << (*pointToPairP).x << "\n";
    std::cout << "(*pointToPairP).y: " << (*pointToPairP).y << "\n";
};

int sumUsingPointerAndPlusPlus(int* begin, int n) {
    int sum = 0;
    int* end = begin + n;
    for (int* ptr = begin; ptr < end; ptr++) {
        sum += *ptr;
    }
    return sum;
};

void testSumUsingPointerAndPlusPlus() {
    int myArray[5]= {1, 2, 3, 4, 5};
    int total = sumUsingPointerAndPlusPlus(myArray, 5);
    std::cout<< "Sum Using Pointer And Plus Plus: " << total << '\n';
};

void constPointerExamples() {
    const char* wordPtr = "leo lo";
    //cannot change data
    wordPtr++;

    std::cout<< "The word pointer: " << (*wordPtr) << '\n';


    char* fiveChars = new char[5];
    char *const wordPtr2 = fiveChars;
    // cannot perform pointer operatioin
    (*wordPtr2) = 'a';
    std::cout << "The word pointer 2: " << (*fiveChars) << '\n';
    delete[] fiveChars;

}

char* thisFunctionReturnsAPointer(){
    char text[] = "This works";
    int n = strlen(text);
    char* ret = new char[n+1];
    strcpy(ret, text);
    return ret;
}

void someOtherFunction(){
    char text[] = "Leo Lo";
    std::cout << text << "\n";
}

void testReturnPointerJustAboutOK() {
    char* text = thisFunctionReturnsAPointer();
    someOtherFunction();
    std::cout << text << "\n";
    delete[] text;
}