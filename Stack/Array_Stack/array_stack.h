#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include <vector>

class ArrayStack
{
private:
    std::vector<int> stack;

public:
    int size();
    bool isEmpty();
    void push(int num);
    int pop();
    int top();
    std::vector<int> toVector();
};


#endif