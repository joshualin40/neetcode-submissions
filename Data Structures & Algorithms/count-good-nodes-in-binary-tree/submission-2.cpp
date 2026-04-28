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
// max should only be for the largest seen so far. but the max is 
// being updated each time
    void preOrder(TreeNode* root, int& count, int max)
    {
        if (root == nullptr) return;
        if (root->val >= max)
        {
            count++;
            max = root->val;
        }
      
        preOrder(root->left, count, max); // max is
        preOrder(root->right, count, max);

        return;
    }
    int goodNodes(TreeNode* root) {
        // root is always good
        // DFS preorder. while going, track the max value of the tree so far
        // recursion 
        int count = 0;
        int max = INT_MIN;
        preOrder(root, count, max);
        return count;
    }
};
