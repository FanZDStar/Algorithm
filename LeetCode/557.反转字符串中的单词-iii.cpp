/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> splitIntoWords(const string &sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    void reverseString(string &s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        vector<string> words = splitIntoWords(s);
        for (auto &word : words) {
            reverseString(word);
        }
        string results;
        for (size_t i = 0; i < words.size(); ++i) {
            results.append(words[i]);
            if (i < words.size() - 1) {
                results.append(" ");
            }
        }
        return results;
    }
};

// @lc code=end

