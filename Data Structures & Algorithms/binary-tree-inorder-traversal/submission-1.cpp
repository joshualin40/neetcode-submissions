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
    vector<int> inorderTraversal(TreeNode* root) {
        // keep going left until you cant
        // when you cant. pop and then go right
        // if you cant go left or right add current node to vec
        vector<int> res; 
        stack<TreeNode*> s;
        if (root == nullptr) return res;
        TreeNode* current = root; 


        while (!s.empty() || current)
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            res.push_back(current->val);
            current = current->right; // only go once, as the right child
            // could have a left child, and we need to go left whenever possible
        }

        return res;
    }
};