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

 // delete all LEAF nodes with value target

 // DFS
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // process children before parents -> postorder traversal
        if (!root) return nullptr; 

        if (root->left) root->left = removeLeafNodes(root->left, target); 
        if (root->right) root->right = removeLeafNodes(root->right, target); 


         if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }

        return root;
    }
};