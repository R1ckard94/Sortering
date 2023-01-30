//
//  dataReport.cpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-27.
//

#include "dataReport.hpp"


void makeReport(){
    std::vector<int> vec;
    std::vector<double> mesurements;
    std::cout<<"N       T[s]        Stdev[s]        Samples"<<std::endl;
    for(int i = MIN_ELEMENTS_TO_SORT; i<=MAX_ELEMENTS_TO_SORT; i+=MIN_ELEMENTS_TO_SORT){
        for(int j = 0; j<SAMPLES; j++){
            Time time;

            /* Ändra här för att använda data sorterat i olika former*/
            vec = randomData(i); 
            //vec = monoRisingData(i);
            //vec = monoFallingData(i);
            //vec = constantData(i);
            //vec = customData();
            Sort sort(vec);

            time.start();
            /* Val av sorteringsalgoritm */
            //sort.insertionSort(); //1.
            //sort.selectionSort(); //2.
            //sort.quickSort();     //3.
            sort.quickSortMedianOf3(); //4.
            
            time.stop();
            if(!sort.isSorted()){
                std::cout<<"is not sorted\n";
            }

            mesurements.push_back(time.time());
            vec.clear();
        }
        
        std::cout<<i<<"   "<<printAvg(mesurements)<<"   "<<std_dev(mesurements)<<"        "<<SAMPLES<<std::endl;
        mesurements.clear();

    }
}

//standardavvikelse
double std_dev(std::vector<double> measurements){
    double sum = std::accumulate(measurements.begin(), measurements.end(), double());
    auto n = measurements.size();
    auto avg = sum/measurements.size();
    std::vector<double> dev_square;
    for(int i = 0; i<measurements.size(); i++){
        dev_square.push_back(std::pow(measurements[i] - avg, 2));
    }
    //std::vector<double> dev_square = std::pow(measurements[i] - avg, 2);
    double square_sum = std::accumulate(dev_square.begin(), dev_square.end(), double());
    
    return std::sqrt(square_sum * (1.0/(n - 1)));
}

double printAvg(std::vector<double> measurements){
    double sum = std::accumulate(measurements.begin(), measurements.end(), double());
    auto avg = sum/measurements.size();
    return avg;
}
