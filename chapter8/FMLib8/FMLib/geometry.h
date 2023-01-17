#pragma once

const double PI = 3.1415926535897932384626433832795028842;

class Circle {
public:
    double radius;
    double area();
    double circumference();
};

class CartesianPoint {
public:
    double x;
    double y;
};

class PolarPoint {
public:
    double r;
    double theta;
};



/**
 *   Computes the area of a circle
 */
double areaOfCircle(double r);

/**
 *  Computes the circumference of a circle
 */
double circumferenceOfCircle(double r);

/**
 *   Converts Cartesian coordinates to polar coordinates. Note this
 *   changes r and theta.
 */
PolarPoint cartesianToPolar( const CartesianPoint& );

/**
 *  Converts polar coordinates to cartesian. Note, this changes x and y.
 */
CartesianPoint polarToCartesian( const PolarPoint& );


/**
 *  Test suite
 */
void testGeometry();