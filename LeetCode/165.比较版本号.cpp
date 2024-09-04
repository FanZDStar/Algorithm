/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int l=0,r=0;
        while(l<n1||r<n2)
        {
            long long x=0,y=0;
            while(l<n1&&version1[l]!='.') x=x*10+version1[l++]-'0';
            l++;//跳过点号
            while(r<n2&&version2[r]!='.') y=y*10+version2[r++]-'0';
            r++;//跳过点号
            if(x<y) return -1;
            else if(x>y) return 1;
        }
        return 0;
    }
};

// @lc code=end

