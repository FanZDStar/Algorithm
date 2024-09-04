/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
public:
    // 用于存储字符在外星字母表中的位置
    vector<int> index;

    Solution() : index(26) {} // 初始化index数组

    bool compare(const string& a, const string& b) {
        int k = min(a.size(), b.size());
        for (int i = 0; i < k; i++) {
            if (a[i] != b[i]) {
                // 比较两个字符在外星字母表中的位置
                if (index[a[i] - 'a'] < index[b[i] - 'a']) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        // 如果没有找到不同字符，则较短的词应在前面
        return a.size() <= b.size();
    }

    bool isAlienSorted(vector<string>& words, string order) {
        // 设置字符在外星字母表中的位置
        for (int i = 0; i < order.size(); i++) {
            index[order[i] - 'a'] = i;
        }

        // 验证词典中的每对相邻词
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i + 1])) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

