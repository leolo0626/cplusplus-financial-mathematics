#pragma once

#include "stdafx.h"

const double PI = 3.14159265358979;

/**
 *  Computes the cumulative
 *  distribution function of the
 *  normal distribution
 */
double normcdf( double x );

/**
 *  Computes the inverse of normcdf
 */
double norminv( double x ); 

/**
 *  Test function
 */
void testMatlib();