#include "SelectionAlgorithm.h"

class AlgorithmSortAll : public SelectionAlgorithm{
public:
	AlgorithmSortAll(vector<int>*,int);
	~AlgorithmSortAll();
protected:
	int select();
};

