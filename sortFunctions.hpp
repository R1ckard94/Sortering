//
//  sortFunctions.hpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-22.
//

#ifndef sortFunctions_hpp
#define sortFunctions_hpp

#include <iostream>
#include <vector>
#include <algorithm>            
#include <cassert>
#include <functional>
#include <iterator>
#include <cmath>



class Sort{
    std::vector<int> vector;
    void swap(int *a, int *b);
    void heapStruct(std::vector<int>::iterator begin, std::vector<int>::iterator end, int size, std::vector<int>::iterator i);
    void heapSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void QuickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t depth);
public:

    Sort(std::vector<int>& vec);
    void STLSort();
    void insertionSort();
    void selectionSort();
    void quickSort();
    void quickSortMedianOf3();
    bool isSorted();
    void printVector();

    
};
template<class FwdIt, class Compare = std::less<>>
void quick_sort(FwdIt first, FwdIt last, Compare cmp = Compare{}) { //quciksort median of 3
    auto const N = std::distance(first, last);
    if (N <= 1) return;
    auto const pivot = *std::next(first, N / 2);
    auto const middle1 = std::partition(first, last, [=](auto const& elem){
        return cmp(elem, pivot);
    });
    auto const middle2 = std::partition(middle1, last, [=](auto const& elem){
        return !cmp(pivot, elem);
    });
    quick_sort(first, middle1, cmp);
    quick_sort(middle2, last, cmp);  
}

#endif /* sortFunctions_hpp */
