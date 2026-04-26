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
// do any type of traversal to convert each to a vector, 


class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &res)
    {
        if (!root) 
        { res.push_back(-1);
        return;
        }
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1; vector<int> q1;
        preOrder(p,p1);
        preOrder(q,q1);
        return (p1 == q1);
    }
};
