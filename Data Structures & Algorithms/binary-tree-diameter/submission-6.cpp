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

// use DFS with queue, update global var each time
class Solution {
public:
    int getHeight(TreeNode* root)
    {
        if (root == nullptr) return 0;

        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        int res = getHeight(root->left) + getHeight(root->right);
        q.push(root);
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            int height = getHeight(temp->left) + getHeight(temp->right);
            if (height > res) res = height;
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
        return res; 
    }
};
