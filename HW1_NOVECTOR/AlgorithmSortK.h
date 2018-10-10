#include "SelectionAlgorithm.h"

class AlgorithmSortK : public SelectionAlgorithm{
public:
    explicit AlgorithmSortK(int);
	~AlgorithmSortK();
protected:
	int select();
private:
	int* pArr;
	void sortPartedArr(int*);
};

