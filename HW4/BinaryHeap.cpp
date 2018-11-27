//============================================================================
// Name        : BinaryHeap.cpp
// Author      : Hasan Sozer
// Version     : 1.2
// Copyright   : (c) 2013 Ozyegin University
// Description : Includes the (incomplete) implementation file of the  
//               BinaryHeap class that will be used as part of the program    
//               to be submitted as Homework 3, which is assigned in the   
//               context of the course CS201, Data Structures and Algorithms.
//               
//               THE IMPLEMENTATION MUST BE COMPLETED TO MAKE ALL THE TESTS
//               IN THE MAIN METHOD PASS.
//
//               After completing the heap implementation, "BinaryHeap.h" and
//               "BinaryHeap.cpp" files will be used for extending homework 1,
//               and the extended program will be submitted as Homework 3.
//============================================================================

#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
    this->capacity = capacity;

    // The element at index 0 is not used!
    // The root element will be placed at index 1
    heap = new int[capacity + 1];
    size = 0;
}

BinaryHeap::~BinaryHeap() {
    delete[] heap;
}

void BinaryHeap::insert(int element) {
    if (size < capacity) {
        int location = ++size;
        for (; location > 1 && element < heap[location / 2]; location /= 2)
            heap[location] = heap[location/2];
        heap[location] = element;
    }
}

void BinaryHeap::deleteMin() {
    if(size < 1)
        return;
    heap[1] = heap[size];
    heap[size--] = 0;
    percolateDown(1);
    // If the size is less than 1, do nothing and stop
    // Otherwise, replace the root of the heap with the last element on the last level
    // Then, call the percolateDown function by providing the index of the root node, i.e., 1
}

int BinaryHeap::getMin() {
    return size < 1 ? -1 : heap[1];
    // If the size is less than 1, return -1
    // Otherwise, return the value of the root node
}

void BinaryHeap::percolateDown(int hole) {
    if(hole*2 < size && heap[hole*2] >= 0){
        int leftChild = heap[hole*2];
        int rightChild = (hole*2 <= size && (heap[hole*2+1] >= 0)) ? heap[hole*2+1] : INT_MAX;
        int swapIndex = (leftChild >= rightChild) ? hole*2+1 : hole*2;
        if(heap[hole] > heap[swapIndex]) {
            swap(hole, swapIndex);
            percolateDown(swapIndex);
        }
    }
    // Compare the node with its children; if they are in the correct order, stop
    // Otherwise, swap the element with the smallest child
    // Repeat the operation for the swapped child node
}

void BinaryHeap::swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}
