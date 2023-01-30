//
//  dataGenerate.hpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-27.
//

#ifndef dataGenerate_hpp
#define dataGenerate_hpp

#include <iostream>
#include <cmath>
#include <vector>
std::vector<int> customData();
std::vector<int> randomData(int size);
std::vector<int> monoRisingData(int size);
std::vector<int> monoFallingData(int size);
std::vector<int> constantData(int size);

#endif /* dataGenerate_hpp */
