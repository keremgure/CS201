#ifndef _VECTOR_STREAM_
#define _VECTOR_STREAM_
#include <vector>
#include <iostream>
#define SORTALL 1 
#define SORTK 4
using namespace std;
#endif //_VECTOR_STREAM_

#ifndef _SEL_
#define _SEL_
class SelectionAlgorithm{
public:
	SelectionAlgorithm(vector<int>&, int);
	virtual ~SelectionAlgorithm() {};
	virtual int select() = 0;
protected:
	int k;
	vector<int>*arr;
};
#endif //_SEL_