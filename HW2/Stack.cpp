#include "Stack.h"

Stack::Stack() {
    this->head = nullptr;
    this->vec = new vector<StackItem*>;
}

Stack::~Stack() {
    if(!isEmpty()) {
        delete this->head;
        head = nullptr;
    }
    this->vec->erase(this->vec->begin(),this->vec->end());
    delete this->vec;
    this->vec = nullptr;
}

void Stack::push(StackItem *item) {
    StackItem *temp = this->head;
    this->head = item;
    item->next = temp;
}

StackItem* Stack::pop() {
    StackItem *temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;
    this->vec->push_back(temp);

    return temp;
}

StackItem* Stack::top() {
    return this->head;

}

bool Stack::isEmpty() {
    return this->head == nullptr;
}

Stack* Stack::flush() {
    delete this;
    return nullptr;
}
