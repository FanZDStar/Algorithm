/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start

#include <iostream>
#include <stack>
using namespace std;


class MinStack {
private:
stack<int> stk;
stack<int> minStk;
public:
    MinStack(){}
    
    void push(int val);
    
    void pop();
    
    int top();
    
    int getMin();
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void MinStack::push(int val){
    stk.push(val);
    if(minStk.empty() || val <= minStk.top())
        minStk.push(val);
    else
        minStk.push(minStk.top());
}
void MinStack::pop(){
    stk.pop();
    minStk.pop();
}
int MinStack::top(){
    return stk.top();
}
int MinStack::getMin(){
    return minStk.top();
}
// @lc code=end

