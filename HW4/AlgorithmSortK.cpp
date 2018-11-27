#include "AlgorithmSortK.h"


AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k){

}

int AlgorithmSortK::select() {
	int N;
	cin >> N;
	pArr = new int[this->k];
	for(int i = 0; i<k;i++)
		cin >> pArr[i];
	sortPartedArr(pArr);

	for (int j = this->k; j < N; j++) {
		int key;
		cin >> key;
		int t = this->k - 1;
		while (key > pArr[t] && t >= 0) {
		    if (t != 0)
		        pArr[t] = pArr[t - 1];
		    t = t - 1;
			}
			pArr[t + 1] = key;
	}
	return pArr[this->k - 1];
}

void AlgorithmSortK::sortPartedArr(int* a) {
	int n = this->k;
	int j;

	for (int i = 1; i < n; i++) {
		j = i - 1;
		int key = a[i];
		while (j >= 0 && a[j] < key){
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}

}

AlgorithmSortK::~AlgorithmSortK(){
	delete[] pArr;
	pArr = nullptr;//or use unique_ptr!!
}
