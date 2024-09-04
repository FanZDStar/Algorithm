/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

// @lc code=start

class Solution {
public:
    string validIPAddress(string IP) {
        // 检查是否为 IPv4 地址
        if (count(IP.begin(), IP.end(), '.') == 3){
            vector<string> parts;
            stringstream ss(IP);
            string part;
            while (getline(ss, part, '.')) {
                parts.push_back(part);
            }
            if (parts.size() != 4) {
                return "Neither";
            }
            for (const string& part : parts){
                if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0')) {
                    return "Neither";
                }
                for (char c : part){
                    if (!isdigit(c)){
                        return "Neither";
                    }
                }
                if (stoi(part) > 255) {
                    return "Neither";
                }
            }
            
            return "IPv4";
        }
        
        // 检查是否为 IPv6 地址
        if (count(IP.begin(), IP.end(), ':') == 7){
            vector<string> parts;
            stringstream ss(IP);
            string part;
            while (getline(ss, part, ':')) {
                parts.push_back(part);
            }
            if (parts.size() != 8) {
                return "Neither";
            }
            for (const string& part : parts){
                if (part.empty() || part.size() > 4 ) {
                    return "Neither";
                }
                for (char c : part){
                    if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};


// @lc code=end

