#pragma once

template <class TYPE> class Stack {
private:
    TYPE* stack;
    int logicalSize;
    int physicalSize;

public:
    Stack();
    Stack(int newLogicalSize);
    TYPE* getStack() { return this->stack; }
    void push(TYPE newStack);
    void pop();
    bool is_empty();
};

template <class TYPE> Stack<TYPE>::Stack() {
    this->logicalSize = 0;
    this->physicalSize = 1;
    this->stack = new TYPE[1]; ;
}

template <class TYPE> Stack<TYPE>::Stack(int newLogicalSize) {
    this->logicalSize = newLogicalSize; 
    this->physicalSize = newLogicalSize + 1; 
    this->stack = new TYPE[newLogicalSize + 1]; 
}

template <class TYPE> void Stack<TYPE>::push(TYPE newStack) {
    TYPE* temp = new TYPE[this->physicalSize + 1];
    int i = 0;
    for (i = 0; i < this->physicalSize; i++) {
        temp[i] = this[i];
    }
    temp[i++] = newStack;
    this->logicalSize++;
    this->physicalSize++;
    this = temp;
    delete temp;
}

template <class TYPE> void Stack<TYPE>::pop() {
    TYPE* temp = new TYPE[this->physicalSize - 1];
    for (int i = 0; i < this->physicalSize - 1 ; i++) {
        temp[i] = this[i];
    }
    this->logicalSize--;
    this->physicalSize--;
    this = temp;
    delete temp;
}

template <class TYPE> bool Stack<TYPE>::is_empty() {
    return this->logicalSize == 0;
}

