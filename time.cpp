//
//  time.cpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-22.
//

#include "time.hpp"

Time::Time(){

}

void Time::start(){
    this->begin = std::chrono::high_resolution_clock::now();
}

void Time::stop(){
    this->end = std::chrono::high_resolution_clock::now();
}

void Time::printTime(){
    std::chrono::duration<double> time_span = duration_cast<std::chrono::duration<double>>(this->end - this->begin);
    std::cout << "Time taken: " << time_span.count() <<" seconds.\n";
}
double Time::time(){
    std::chrono::duration<double> time_span = duration_cast<std::chrono::duration<double>>(this->end - this->begin);
    return time_span.count();
 
}
