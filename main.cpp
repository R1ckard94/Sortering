//
//  main.cpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-22.
//

#include <iostream>
#include <vector>
#include "sortFunctions.hpp"
#include "time.hpp"
#include "dataGenerate.hpp"
#include "dataReport.hpp"


int main() {
    
    Time time2;
    time2.start();
    makeReport();
    time2.stop();
    
    std::cout<<std::endl<<std::endl;
    time2.printTime();
    
    
    
}
