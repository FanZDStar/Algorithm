/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; // 指向写入位置
        int read = 0;  // 指向读入位置
        int length = chars.size();
        
        while (read < length) {
            char current = chars[read];
            int count = 0;
            
            // 计算当前字符的连续出现次数
            while (read < length && chars[read] == current) {
                count++;
                read++;
            }
            
            // 写入当前字符
            chars[write++] = current;
            
            // 如果出现次数大于1，写入次数
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};

// @lc code=end

