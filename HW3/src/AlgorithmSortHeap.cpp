#include "AlgorithmSortHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k){
    heap = new BinaryHeap(this->k);

}

int AlgorithmSortHeap::select() {
    int N;
    cin >> N;
    for(int i = 0; i < this->k; i++) {
        int t;
        cin >> t;
        heap->insert(t);
    }

    int j = N - k;
    while(j-- > 0){
        int t;
        cin >> t;
        if(t < heap->getMin())
            continue;
        heap->deleteMin();
        heap->insert(t);
    }
    return heap->getMin();

}

AlgorithmSortHeap::~AlgorithmSortHeap() {
    delete heap;
}
