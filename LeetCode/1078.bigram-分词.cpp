/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
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

    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> results = splitIntoWords(text);
        vector<string> ans;
        int length = results.size();
        for(int i = 0; i < length - 1; i++){
            if(results[i] == first && results[i+1] == second){
                if(i+2 < length )
                    ans.push_back(results[i + 2]);
            }
        }
        return ans;
    }
};
// @lc code=end

