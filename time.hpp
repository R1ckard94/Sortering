//
//  time.hpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-22.
//

#ifndef time_hpp
#define time_hpp

#include <iostream>
#include <chrono>

class Time{
public:
    std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point end;
    Time();
    void start();
    void stop();
    void printTime();
    double time();
    
};

#endif /* time_hpp */
