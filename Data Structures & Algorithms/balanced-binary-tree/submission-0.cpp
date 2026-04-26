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
    int getHeight(TreeNode* root, bool& isBalanced)
    {
        if (root == nullptr) return 0;
        if (abs(getHeight(root->left, isBalanced) - getHeight(root->right, isBalanced)) > 1) isBalanced = false;
        return 1 + max(getHeight(root->left, isBalanced), getHeight(root->right, isBalanced));
    }
    bool isBalanced(TreeNode* root) {
        bool Balanced = true;
        getHeight(root, Balanced);
        return Balanced;
    }
};
