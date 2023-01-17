#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void writeText( ostream & out );

void writeString();

int main() {

    writeText(cout);

    ofstream out;

    out.open("myfile.txt");

    writeText(out);

    out.close();

    writeString();
    return 1;
}


void writeText( ostream & out) {
    out << "Hi i am Leo \n" ;
    out << "I am 28 years old \n";
};

void writeString () {
    stringstream ss;
    for (int i = 0; i< 100; i++) {
        ss << "I am Leo";
    }
    string s1 = ss.str();
    cout << s1 << "\n";
}
