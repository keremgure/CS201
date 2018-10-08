#include "AlgorithmSortAll.h"


AlgorithmSortAll::AlgorithmSortAll(vector<int>*arr,int k) : SelectionAlgorithm(*arr,k){

}

int AlgorithmSortAll::select() {
	int n = (this->arr)->size();
	int j;

	for (int i = 1; i < n; i++){
		j = i - 1;
		 int key = (this->arr)->at(i);

		while (j >= 0 && (this->arr)->at(j) < key)
		{
			(this->arr)->at(j + 1) = (this->arr)->at(j);
			j = j - 1;
		}
		(this->arr)->at(j + 1) = key;
	}

	return this->arr->at(k);
}




AlgorithmSortAll::~AlgorithmSortAll(){
	//this->arr->~vector();
	delete this->arr;
	this->arr = 0;

}
