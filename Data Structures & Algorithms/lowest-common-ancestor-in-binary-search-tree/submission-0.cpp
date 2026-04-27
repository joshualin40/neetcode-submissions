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
// BST: ALl right nodes are larger, all left nodes are smaller than parent
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return res such that p and q are both children of res
        // or res is equal to p/q and the other is a child

        // this is our recursive function: 
            // if both are greater than root, go right
            // else if both are less than root, go left
            // else return the root (either both are children of the root
            // or one of them is the root)
    
        // base case: 
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, q, p);
        else if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, q, p);
        else return root; 

        
    }
};
