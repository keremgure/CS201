#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include <ctime>

class TestBed{
public:
	TestBed(vector<int>&);
	~TestBed();
	void execute();
private:
	SelectionAlgorithm *algorithm;
	void setAlgorithm(int);
	vector<int>*arr;
	int k;
};