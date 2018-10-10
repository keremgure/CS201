#ifndef _VECTOR_STREAM_
#define _VECTOR_STREAM_
#include <vector>
#include <iostream>
#define SORTALL 1 
#define SORTK 2
using namespace std;
#endif //_VECTOR_STREAM_

#ifndef _SEL_
#define _SEL_
class SelectionAlgorithm{
public:
	explicit SelectionAlgorithm(int);
	virtual ~SelectionAlgorithm() = default;
	virtual int select() = 0;
protected:
	int k;
};
#endif //_SEL_