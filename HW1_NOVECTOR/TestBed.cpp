#include "TestBed.h"


TestBed::TestBed() = default;

void TestBed::setAlgorithm(int a) {
	int k;
	cin >> k;
	switch (a){
	case (SORTALL):
		algorithm = new AlgorithmSortAll(k);
	case (SORTK):
		algorithm = new AlgorithmSortK(k);
	default:
		break;
	}
}


void TestBed::execute() {
    int algType;
    cin >> algType;
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
	algorithm = nullptr;
}
