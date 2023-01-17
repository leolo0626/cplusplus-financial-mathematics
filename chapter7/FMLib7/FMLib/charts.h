#pragma once

#include "stdafx.h"


/**
 *   Write a pie chart
 */
void pieChart( std::string& file,
			   std::vector<std::string>& labels,
		 	   std::vector<double>& values );


/**
 *   Run unit tests for the charts package
 */
void testCharts();