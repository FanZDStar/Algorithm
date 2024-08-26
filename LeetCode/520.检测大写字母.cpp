/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0] >= 'A' && word[0] <= 'Z'){
            if(word[1] >= 'A' && word[1] <= 'Z'){
                for(int i = 2; i <= word.size() - 1; i++){
                    if(word[i] >= 'a' && word[i] <= 'z'){
                        return false;
                    }
                }
                return true;
            }
            else{
                for(int i = 2; i <= word.size() - 1; i++){
                    if(word[i] >= 'A' && word[i] <= 'Z'){
                        return false;
                    }
                }
                return true;
            }
        }

        else{
            for(int i = 1; i <= word.size() - 1; i++){
                    if(word[i] >= 'A' && word[i] <= 'Z'){
                        return false;
                    }
                }
                return true;
        }
        
    }
};
// @lc code=end

