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
    pair<int, bool> dfs(TreeNode* root)
    {
        if (root == nullptr) return {0, true};

        int height = max(dfs(root->left).first, dfs(root->right).first) + 1;
        bool isBalanced = (dfs(root->left).second && dfs(root->right).second
                            && (abs(dfs(root->left).first - dfs(root->right).first) <= 1));

        return {height, isBalanced};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};
