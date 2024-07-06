#include "queue.h"
using namespace std;

array_queue::array_queue(int capacity)
{
    nums = new int[capacity];
    queCapacity = capacity;
    front = queSize = 0;
}

array_queue::~array_queue()
{
    delete []nums;
}


int array_queue::capacity()
{
    return queCapacity ;
}

bool array_queue::isEmpty()
{
    return queSize == 0;
}


int array_queue::size()
{
    return queSize;
}

void array_queue::push(int num)
{
    if(queSize == queCapacity)
    {
        cout<< "队列已满" << endl;
        return ;
    }
    // 利用取余操作越过尾部返回头部
    int rear = (front+ queSize) % queCapacity;
    nums[rear] = num;
    queSize++;
}


int array_queue::pop()
{
    int num = peek();

    // 指针向后移动一位，若越过尾部，则返回到数组头部
    front = (front + 1) % queCapacity;
    queSize--;
    return num;
}


int array_queue::peek()
{
    if(isEmpty())
        throw out_of_range("队列为空");
    return nums[front];
}