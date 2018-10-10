#include "AlgorithmSortAll.h"


AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k){
}

int AlgorithmSortAll::select() {
	int N;
	cin >> N;
	pArr = new int[N];
	for(int m = 0; m<N;m++)
		cin >> pArr[m];

	int j;
	for (int i = 1; i < N; i++){
		j = i - 1;
		int key = pArr[i];

		while (j >= 0 && pArr[j] < key) {
			pArr[j + 1] = pArr[j];
			j = j - 1;
		}
		pArr[j + 1] = key;
	}
	return pArr[k];
}

AlgorithmSortAll::~AlgorithmSortAll(){
	delete [] pArr;
	pArr = nullptr;

}
