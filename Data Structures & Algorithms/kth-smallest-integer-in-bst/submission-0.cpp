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
    // DFS. find the smallest value first, then go up k-1 times. inOrderTraversal 
public:
    int kthSmallest(TreeNode* root, int k) {

        // keep going left until you cant
        // when you cant. pop and then go right
        // if you cant go left or right add current node to vec
        vector<int> res; 
        stack<TreeNode*> s;
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

        return res[k-1];
    }
};
