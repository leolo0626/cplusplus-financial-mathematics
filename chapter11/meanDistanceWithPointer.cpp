#include <cmath>
#include <iostream>

class Pair {
    public:
        double x;
        double y;
        Pair();
        Pair(double x, double y);
};

double meanDistanceWithPointer(Pair* pairs, int length);

int main() {
    Pair p1 = Pair(2.0, 4.0);
    Pair p2 = Pair(3.0, 5.0);
    Pair pairList[2] = {p1, p2};
    std::cout << "Mean Distance: " << meanDistanceWithPointer(pairList, 2) << "\n";
    return 0.0;
}

Pair::Pair():
    x(0.0), y(0.0) {};

Pair::Pair(double x, double y):
    x(x), y(y) {};

double meanDistanceWithPointer(Pair* pairs, int length) {
    Pair* end = pairs + length;
    double totalDistance = 0.0;
    for (Pair* ptr = pairs; ptr < end; ptr ++ ){
        double x = ptr->x;
        double y = ptr->y;
        totalDistance += std::sqrt(x*x + y*y);
        // std::cout << "totalDistance: " << totalDistance << "\n";
    }
    return totalDistance / length;
}