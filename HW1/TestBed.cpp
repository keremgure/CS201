#include "TestBed.h"


TestBed::TestBed(vector<int>&arr){
	this->arr = &arr;
	this->k = 0;
	this->algorithm = 0;
}

void TestBed::setAlgorithm(int a) {
	switch (a){
	case (SORTALL):
		algorithm = new AlgorithmSortAll(this->arr, k);
	case (SORTK):
		algorithm = new AlgorithmSortK(this->arr, k);
	default:
		break;
	}
}


void TestBed::execute() {
	int algType = this->arr->at(0);
	k = this->arr->at(1);

	this->arr->erase(this->arr->begin(), this->arr->begin()+3);//Delete first 3 identifier elements from the input array.
	setAlgorithm(algType);
	
	
	//Check the clock.
	clock_t start = clock();

	int result = algorithm->select();

	//Check clock again then calculate.
	clock_t end = clock();

	double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;


	cout << "Result: " << result << endl;
	cout <<"Duration (sec): " << cpu_time << endl;
}


TestBed::~TestBed(){
	//algorithm->~SelectionAlgorithm();
	delete algorithm;
	algorithm = 0;
}
