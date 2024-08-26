/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    void fzstring(string& s,int start,int end){//函数：用来反转 ,&必须加,不加就...(过不了了)
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    string reverseStr(string s, int k) {
        
        int l = s.size();
        for(int i = 0; i < l; i += (2*k))
        {
            if(i + k < l){fzstring(s, i , i + k - 1);continue;}
                
            fzstring(s,i,l-1);
        }
        
        return s;
    }
};
// @lc code=end

