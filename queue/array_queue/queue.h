#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#include <stdexcept>

class array_queue
{
private:
    int *nums;
    int front;
    int queSize;
    int queCapacity;
public:
    array_queue(int capacity);
    ~array_queue();
    int capacity();
    int size();
    bool isEmpty();
    void push(int num);
    int pop();
    int peek();
    std::vector<int> toVector();

};
#endif // QUEUE_H