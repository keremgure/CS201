#include "AlgorithmSortK.h"



AlgorithmSortK::AlgorithmSortK(vector<int>*arr,int k) : SelectionAlgorithm(*arr,k){
}


int* pArr;
int AlgorithmSortK::select() {
	pArr = new int[this->k];

	for (int i = 0; i < this->k; i++) {
		pArr[i] = this->arr->at(i);
	}
	sortPartedArr(pArr);


	for (unsigned int j = this->k; j < this->arr->size(); j++) {
		int key = this->arr->at(j);
		int t = this->k - 1;
		if (key > pArr[t]) {
			while (key > pArr[t] && t >= 0) {
				if (t != 0)
					pArr[t] = pArr[t - 1];
				t = t - 1;
			}
			pArr[t + 1] = key;
		}
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
	delete this->arr;
	//this->arr->~vector();
	this->arr = 0;
	delete[] pArr;
	pArr = 0;//or use unique_ptr!!
}
