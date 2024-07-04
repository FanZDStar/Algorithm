#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> map;
    /* 添加操作 */
    // 在哈希表中添加键值对 (key, value)
    map[12836] = "小哈";
    map[15937] = "小啰";
    map[16750] = "小算";
    map[13276] = "小法";
    map[10583] = "小鸭";

    /* 查询操作 */
    // 向哈希表中输入键 key ，得到值 value
    std::string name = map[15937];

    /* 删除操作 */
    // 在哈希表中删除键值对 (key, value)
    map.erase(10583);
    // 遍历
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        std::cout << iter->first << "->" << iter->second << std::endl;
    }
    for (auto kv : map)
    {
        std::cout << kv.first << " -> " << kv.second << std::endl;
    }
    return 0;
}