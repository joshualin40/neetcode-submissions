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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; 
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else // key is equal to the root val. delete it 
        {
            // if it has one child
            if (!root->left && root->right) return root->right;
            if (!root->right && root->left) return root->left;
            // if two children, replace current node C with the smallest node from the 
            // right subtree of C, then delete that node
            if (root->left && root->right)
            {
                TreeNode* current = root->right;
                TreeNode* parent;
                while (current->left)
                {
                    parent = current;
                    current = current->left;
                }
                root->val = current->val; // now there are two nodes with teh same value
                root->right = deleteNode(root->right, root->val);
            }
            // if no children, just delete it 
            if (!root->left && !root->right)
                root = nullptr; 
        }

        return root; 
    }
};