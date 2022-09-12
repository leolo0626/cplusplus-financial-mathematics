#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::vector<double> myVector;
    myVector.push_back(12.0);
    myVector.push_back(13.0);
    
    std::vector<double> ten3s(10, 3.0);
    std::vector<double> copy(ten3s); 

    // std::vector<int> threeInts({ 2, 3, 4});

    std::string s("I am Leo");
    s.insert(5, "more");

    s += " Where am I ?";

    std::cout << "\n" << s << "\n";

    //efficient way to manipulate string
    //string is constant resized during the appending.
    std::stringstream ss;
    for (int i=0; i< 100; i++) {
        ss << "blah ";
    }
    std::cout << ss.str() << "\n" ;
    return 0;

}