/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        istringstream ss(path);
        string part;

        while(getline(ss, part,'/')){
            if(part.empty() || part == "."){
                continue;
            }
            if(part == ".."){
                if(!parts.empty())
                    parts.pop_back();
            }

            else{
                parts.push_back(part);
            }
        }

        string res;
        for(auto &p : parts)
            res += "/" + p;

        return res.empty() ? "/" : res;
    }
};
// @lc code=end

