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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q) return true;

        if (p && q && p->val == q->val)
            return (isSameTree(p->left, q->left) &&
                    isSameTree(p->right, q->right));
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        // use stack to simulate DFS
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* temp = s.top(); s.pop();
            if (isSameTree(temp, subRoot)) return true;
            if (temp->left) s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }

        return false;
    }
};
