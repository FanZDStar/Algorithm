/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> emailSet;
        for (auto &email: emails) {
            string local;
            for (char c: email) {
                if (c == '+' || c == '@') {
                    break;
                }
                if (c != '.') {
                    local += c;
                }
            }
            emailSet.emplace(local + email.substr(email.find('@')));
        }
        return emailSet.size();
    }
};


// @lc code=end

