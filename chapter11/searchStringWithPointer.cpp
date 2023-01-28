#include <iostream>

int searchStringWithPointer(char* phrase, char* text);

int isPhraseInsideSubString(char* phrase, char* text);

int main() {
    char phrase[3] = "be";
    char text[29] = "to be or not to be be be";
    std::cout << "Is Phrase Inside SubString: " << searchStringWithPointer(phrase, text) << "\n";
    return 0;
}

int searchStringWithPointer(char* phrase, char* text) {
    int count = 0;
    char *textPtr = text;
    while (*textPtr != 0 ){
        // 0 means the end of the char 
        char *tempPtr = textPtr;
        count += isPhraseInsideSubString(phrase, tempPtr);
        textPtr++;
    }
    return count;
}

int isPhraseInsideSubString(char* phrase, char* text){
    char* begin = phrase;
    char* textBegin = text;
    while (*begin != 0) {
        if (*text == 0) {
            return 0;
        }
        if (*begin != *textBegin) {
            return 0;
        }
        begin++;
        textBegin++;
    }
    return 1;
}