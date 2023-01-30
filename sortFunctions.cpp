//
//  sortFunctions.cpp
//  Sortering
//
//  Created by Rickard Karlsson on 2021-04-22.
//

#include "sortFunctions.hpp"
Sort::Sort(std::vector<int>& vec){
    this->vector = vec;
    
}

void Sort::STLSort(){ //standard lib sort
    std::sort(this->vector.begin(), this->vector.end());
    
}

void Sort::insertionSort(){

    for (auto step = 1; step < this->vector.size(); step++) { //go through the vector starting from second element
        auto key = this->vector[step];  //add the element to key
        auto prevPos = step - 1;            //and add the previous element to prevPos
        while (key < this->vector[prevPos] && prevPos >= 0) { //check where key fits by going backwards to see if we have anything smaller then the current value for key and not to pass the first element
          this->vector[prevPos + 1] = this->vector[prevPos];    //if key is less we move the value from the previous element forward
          --prevPos;    //set value of prevpos too one less
        }
        this->vector[prevPos + 1] = key;    //when the while loop is false we set value of key to prevPos+1 to counter the step made on row 27
      }
}


void Sort::selectionSort(){
    for (int step = 0; step < this->vector.size() - 1; step++) { //go through all elements except the last one because it will be in order
        int min_idx = step;     //set curr step to smallest int
        for (int i = step + 1; i < this->vector.size(); i++) { //check every element from the position forward

          if (this->vector[i] < this->vector[min_idx])  //if an element is smaller than the smallest currently set element switch them
            min_idx = i;    //give min the index of i
        }
        swap(&this->vector[min_idx], &this->vector[step]);  //swap the values of smallest found int and the positions int
      }
}

void Sort::quickSort(){
    size_t depth = 2*std::log2(this->vector.size()); //depth limit set with the calc of 2 log(vector.size)
    std::vector<int>::iterator start = this->vector.begin();
    std::vector<int>::iterator end = this->vector.end();
    QuickSort(start, end, depth);   //call the quicksort func with the depth and start and end iterators
}

void Sort::quickSortMedianOf3(){
    std::vector<int>::iterator start = this->vector.begin();
    std::vector<int>::iterator end = this->vector.end();
    quick_sort(start, end); //call funtion with start and end iterators
}

bool Sort::isSorted(){  //standard is sorted function
    if(std::is_sorted(this->vector.begin(), this->vector.end())){
        return true;
    }else{
        return false;
        
    }
}


void Sort::swap(int *a, int *b) {   //swap function that switches two values from two elements
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Sort::printVector(){
    for(auto i = 0; i<this->vector.size(); i++){
        std::cout<<this->vector[i]<<" ";
    }
    std::cout<<std::endl;
}



void Sort::QuickSort(std::vector<int>::iterator begin, std::vector<int>::iterator end, size_t depth) { //quicksort vanilla
   if (end == begin){   //base case
        return;
    }
    auto pivot = begin;
    auto middle = begin + 1;
    if(depth == 0){     //har djupet nått 0 så byts sorterings metoden till heapsort för att annars kommer progtrammet att krascha
        heapSort(begin, end);   //heapsort kallas med den osorterade delen
        return;
    }
    for(auto i = begin + 1; i<end; i++){    //partitionerings steg
        if(*i < *pivot){
            std::iter_swap(i, middle);
            middle++;
        }
    }
    --depth;
    //std::iter_swap(begin, middle - 1);
    QuickSort(begin, middle - 1, depth);
    ++depth;
    --depth;
    QuickSort(middle, end, depth);
    ++depth;
}

void Sort::heapStruct(std::vector<int>::iterator begin, std::vector<int>::iterator end, int size, std::vector<int>::iterator i){ //heapify function
    auto largestInt = i; //largest as root
    auto leftIndex = (2*(i-begin)) +1;  //bygger som ett träd med höger och vänster led
    auto left = begin + leftIndex;  //får fram iteratorns index på detta vis
    auto rightIndex = (2*(i-begin)) +2;
    auto right = begin + rightIndex;
    
    if (leftIndex < size && *left > *largestInt){   //kollar om vi har det största elementet
           largestInt = left;
    }
    if (rightIndex < size && *right > *largestInt){ //kollar om vi har det största elementet
            largestInt = right;
    }
    if(largestInt != i){
        std::swap(*i, *largestInt);
        heapStruct(begin, end, size, largestInt);
    }
    
    
}

void Sort::heapSort(std::vector<int>::iterator begin, std::vector<int>::iterator end){ //heapsort 
    int size = static_cast<int>(end-begin);
    for(int i = (size/2)-1; i >= 0 ;i--){
        auto pos = begin + i;
        heapStruct(begin, end, size, pos);
        
        
    }
    for (int i = (size - 1); i > 0; i--) {
            // Move current root to end
            auto pos = begin + i;
            std::swap(*begin, *pos);
            // call max heapy on the reduced heap
            heapStruct(begin, end, i, begin);
        }
    
}
