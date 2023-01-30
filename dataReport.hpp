//
//  dataReport.hpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-27.
//

#ifndef dataReport_hpp
#define dataReport_hpp

#include <iostream>
#include <cmath>
#include <valarray>
#include <numeric>
#include <vector>
#include "sortFunctions.hpp"
#include "time.hpp"
#include "dataGenerate.hpp"

int const MIN_ELEMENTS_TO_SORT = 20000; 
int const MAX_ELEMENTS_TO_SORT = 200000;
int const SAMPLES = 5;

void makeReport();
double std_dev(std::vector<double> measurements);
double printAvg(std::vector<double> measurements);
#endif /* dataReport_hpp */
