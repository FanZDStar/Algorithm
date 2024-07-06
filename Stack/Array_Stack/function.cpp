#include<array_stack.h>
using namespace std;

bool ArrayStack::isEmpty()
{
    return stack.size()==0;
}


int ArrayStack::size()
{
    return stack.size();
}

void ArrayStack::push(int num)
{
    stack.push_back(num);
}

int ArrayStack::top()
{
    if(isEmpty())
        throw out_of_range("空栈");
    return stack.back();
}

vector<int> ArrayStack::toVector()
{
    return stack;
}

