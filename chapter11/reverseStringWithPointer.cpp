#include <iostream>

void reverseStringWithPointer(char* word);

int main() {
    char testWord[10] = "HelloWord";
    reverseStringWithPointer(testWord);
    std::cout<< "Word: " << testWord << "\n";
    return 0;
}

void reverseStringWithPointer(char* word) {
    char* end = word + strlen(word) -1  ;
    for (char* ptr = end; ptr > word; ptr--) {
        char endValue = *ptr;
        *ptr =  *word;
        *word = endValue;
        // std::cout << "Result : " << word << "\n";
        word++;
    }
}