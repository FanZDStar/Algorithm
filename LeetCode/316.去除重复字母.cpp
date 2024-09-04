/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码已经通过力扣的测试用例，应该可直接成功提交。

#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::stack<char> stk;

        // 维护一个计数器记录字符串中字符的数量
        // 因为输入为 ASCII 字符，大小 256 够用了
        std::vector<int> count(256, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
        }

        std::vector<bool> inStack(256, false);
        for (char c : s) {
            // 每遍历过一个字符，都将对应的计数减一
            count[c]--;

            if (inStack[c]) continue;

            while (!stk.empty() && stk.top() > c) {
                // 若之后不存在栈顶元素了，则停止 pop
                if (count[stk.top()] == 0) {
                    break;
                }
                // 若之后还有，则可以 pop
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true;
        }

        std::string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

