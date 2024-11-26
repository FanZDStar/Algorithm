/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if(!root)
            return false;
        queue<TreeNode*>queNode;
        queue<int>queVal;
        queNode.push(root);
        queVal.push(root->val);
        while(!queNode.empty())
        {
            TreeNode *point = queNode.front();
            int temp = queVal.front();
            queNode.pop();
            queVal.pop();
            if(point->left == nullptr && point->right == nullptr)
            {
                if(temp == targetSum)
                    return true;
                else
                    continue;
            }
            if(point->left)
            {
                queNode.push(point->left);
                queVal.push(point->left->val+temp);
            }
            if(point->right)
            {
                queNode.push(point->right);
                queVal.push(point->right->val+temp);
            }
        }
        return false;
    }
};
// @lc code=end
