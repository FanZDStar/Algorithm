/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int countH(TreeNode *root)
    {
        if (!root)
            return 0;
        else
            return max(countH(root->left), countH(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        else
            return abs(countH(root->left) - countH(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
