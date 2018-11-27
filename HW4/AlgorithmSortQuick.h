#ifndef HW3_ALGORITHMSORTQUICK_H
#define HW3_ALGORITHMSORTQUICK_H

#include "SelectionAlgorithm.h"

class AlgorithmSortQuick : public SelectionAlgorithm {
public:
    AlgorithmSortQuick(int);
    ~AlgorithmSortQuick();
    int select();
private:
    int median(int*,int,int);
    int quickselect(int*,int,int,int);
    int* arr;
    int N;
    void insertionSort(int *, int, int);
};


#endif //HW3_ALGORITHMSORTQUICK_H
