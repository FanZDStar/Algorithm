/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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


class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        prev = root->val;
        isUnival = true; // Initialize here to handle multiple calls to isUnivalTree
        traverse(root);
        return isUnival;
    }

private:
    int prev;
    bool isUnival; // Removed the assignment here to avoid reinitialization between calls

    void traverse(TreeNode* root) {
        if (root == nullptr || !isUnival) {
            return;
        }
        if (root->val != prev) {
            isUnival = false;
            return;
        }
        traverse(root->left);
        traverse(root->right);
    }
};
// @lc code=end

