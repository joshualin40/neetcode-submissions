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
// DFS with stack
// use a pair of the node and its depth. 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        int res = 0;
        while (!s.empty())
        {
            TreeNode* temp = s.top().first; 
            int depth = s.top().second;
            s.pop();
            
            res = max(depth, res);
            if (temp->right) s.push({temp->right, depth + 1});
            if (temp->left) s.push({temp->left, depth + 1});
        }
        return res; 
    }
};
