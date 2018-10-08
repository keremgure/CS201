#include "SelectionAlgorithm.h"

class AlgorithmSortK : public SelectionAlgorithm{
public:
	AlgorithmSortK(vector<int>*,int);
	~AlgorithmSortK();
protected:
	int select();
private:
	void sortPartedArr(int*);
};

