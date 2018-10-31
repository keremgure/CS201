#ifndef HW2_STACK_H
#define HW2_STACK_H


#include "StackItem.h"
#include <vector>

class Stack {
public:
    Stack();
    ~Stack();
    StackItem *head;
    void push(StackItem*);

    StackItem* pop();
    StackItem* top();

    bool isEmpty();

    Stack* flush();

};


#endif //HW2_STACK_H
