/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

// @lc code=start
#include <vector>
using namespace std;
#include <string>

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string str[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> h;
        
        for (const auto& word : words) {
            string morseCode;
            for (const char& c : word) {
                morseCode += str[c - 'a'];
            }
            h.insert(morseCode);
        }
        
        return h.size();
    }
};

// @lc code=end

