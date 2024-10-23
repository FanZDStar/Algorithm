/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for(string c : tokens){
            if(c == "+"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int result = a + b;
                stk.push(result);
            }
            else if(c == "-"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int result = b - a;
                stk.push(result);
            }
            else if(c == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int result = b / a;
                stk.push(result);
            }
            else if(c == "*"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int result = a * b;
                stk.push(result);
            }
            else
                stk.push(stoi(c));
        }
        return stk.top();
    }
};
// @lc code=end

