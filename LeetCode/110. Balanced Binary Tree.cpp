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
    int getHeight(TreeNode* node, int height)
    {
        if (node == NULL)
            return height;
        
        return max(getHeight(node->left, height+1), getHeight(node->right, height+1));
    }
    
    
    
    bool isBalanced(TreeNode* root) {
        
        if (root == NULL)
            return true;
        if (abs(getHeight(root->left, 0) - getHeight(root->right, 0)) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};