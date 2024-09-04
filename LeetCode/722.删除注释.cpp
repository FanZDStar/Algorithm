/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

// @lc code=start
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        // 把所有内容放到一行，换行用 ' 标识
        string line;
        for (int i = 0; i < source.size(); ++i) {
            line += source[i] + "'";
        }
        // scan扫描，write写入，去掉注释
        int write = 0, scan = 0, n = line.size();
        while (scan < n) {
            if (scan+1 < n && line[scan] == '/' && line[scan+1] == '/') {
                while (line[scan] != '\'') scan++;
            } else if (scan+1 < n && line[scan] == '/' && line[scan+1] == '*') {
                scan += 2;
                while (!(line[scan] == '*' && line[scan+1] == '/')) scan++;
                scan += 2;
            } else {
                line[write++] = line[scan++];
            }
        }
        // 通过 ' 分割，划分答案
        line = line.substr(0, write);
        vector<string> ans;
        int pre = 0, pos = line.find("'");
        while (pos != -1) {
            string str = line.substr(pre, pos-pre);
            if (!str.empty()) ans.push_back(str);
            pre = pos + 1;
            pos = line.find("'", pre);
        }

        return ans;
    }
};


// @lc code=end

