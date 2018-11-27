#ifndef _SEL_
#define _SEL_

#include <iostream>

#define SORTALL 1
#define SORTK 2
#define SORT_HEAP 3
#define SORT_QUICK 4

using namespace std;

class SelectionAlgorithm{
public:
	explicit SelectionAlgorithm(int);
	virtual ~SelectionAlgorithm() = default;
	virtual int select() = 0;
protected:
	int k;
};
#endif //_SEL_