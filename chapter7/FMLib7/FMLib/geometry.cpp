#include "geometry.h"
#include "stdafx.h"
#include "testing.h"

using namespace std;

/**
 *   Computes the area of a circle
 */
double areaOfCircle(double r) {
	return PI*r*r;
}

/**
 *  Computes the circumference of a circle
 */
double circumferenceOfCircle(double r) {
	return 2*PI*r;
}



/**
 *  Converts polar coordinates to cartesian. Note, this changes x and y.
 */
void polarToCartesian( double r, double theta,
                       double& x, double& y ) {
	x = r*cos(theta);
	y = r*sin(theta);
}

/**
 *   Converts Cartesian coordinates to polar coordinates. Note this
 *   changes r and theta.
 */
void cartesianToPolar( double x, double y, double& r, double& theta ) {
	// Not as easy as it looks to do this
	r = sqrt( x*x + y*y);
	if (y==0.0) {
		if (x>=0.0) {
			theta = 0.0;
		} else if (x<0.0) {
			theta = -PI;
		}
	} else {
		theta = acos( x/r);
		if (y<0) {
			theta = -theta;
		}
	}
}


/////////////////////////////////////////////////
//
//  Geometry tests
//
/////////////////////////////////////////////////

static void testAreaOfCircle() {
	ASSERT_APPROX_EQUAL( areaOfCircle(4), 16*PI, 0.01 );
}

static void testCircumferenceOfCircle() {
	ASSERT_APPROX_EQUAL( areaOfCircle(2), 4*PI, 0.01 );
}

static void testPolarToCartesian() {
	double r = 2.0;
	double theta = PI/2;
	double x=0.0,y=0.0;
	polarToCartesian(r,theta,x,y);
	ASSERT_APPROX_EQUAL( x,0.0,0.001 );
	ASSERT_APPROX_EQUAL( y,2.0,0.001 );
}

static void testCartesianToPolar() {
	// the logic of cartesian to polar is quite complex so we have more tests
	vector<double> angles;
	angles.push_back( 0.0 );
	angles.push_back( PI/4 );
	angles.push_back( PI/2 );
	angles.push_back( 7*PI/8 );
	angles.push_back( PI);
	angles.push_back( -PI/4 );
	angles.push_back( -PI/2 );
	angles.push_back( -7*PI/8 );

	int nAngles = angles.size();
	for (int i=0; i<nAngles; i++) {
		double r = 2.0;
		double theta =angles[i];
		double x=0.0,y=0.0;
		polarToCartesian(r,theta,x,y);
		double rDash=0.0, thetaDash=0.0;
		cartesianToPolar(x,y,rDash,thetaDash );
		ASSERT_APPROX_EQUAL( r,rDash,0.001 );
		ASSERT_APPROX_EQUAL( theta,thetaDash,0.001 );
	}
}




void testGeometry() {
	TEST( testAreaOfCircle );
	TEST( testCircumferenceOfCircle );
	TEST( testPolarToCartesian );
	TEST( testCartesianToPolar );
}