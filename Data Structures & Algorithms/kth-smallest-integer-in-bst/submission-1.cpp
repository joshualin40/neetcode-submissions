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
    int kthSmallest(TreeNode* root, int k) {
        // in order traversla gives the tree in ascending order
        // do in order traversal, adding nodes to an array. rerturn the k-1 element of the array
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* current = root;  

        while (current || !s.empty())
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            res.push_back(current->val);
            current = current->right;
        }

        return res[k-1];
    }
};
