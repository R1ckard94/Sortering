//
//  dataGenerate.cpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-27.
//

#include "dataGenerate.hpp"
std::vector<int> customData(){
    std::vector<int> tmpvec = {23, 5, 2, 1, 82, 99, 21};
    return tmpvec;
}

std::vector<int> randomData(int size){
    srand(time_t(0));
    std::vector<int> tmpvec;
    int temp;
    for(int i = 0; i<size; i++){
        temp = std::rand();
        tmpvec.push_back(temp);
    }
    return tmpvec;
}

std::vector<int> monoRisingData(int size){
    std::vector<int> tmpvec;
    int temp = std::rand()%5;
    for(int i = 0; i<size; i++){
        temp+=5;
        tmpvec.push_back(temp);
    }
    return tmpvec;
}

std::vector<int> monoFallingData(int size){
    std::vector<int> tmpvec;
    int temp = INT32_MAX;
    for(int i = 0; i<size; i++){
        temp-=5;
        tmpvec.push_back(temp);
    }
    return tmpvec;
}

std::vector<int> constantData(int size){
    std::vector<int> tmpvec;
    int temp = std::rand();
    for(int i = 0; i<size; i++){
        tmpvec.push_back(temp);
    }
    return tmpvec;
}
