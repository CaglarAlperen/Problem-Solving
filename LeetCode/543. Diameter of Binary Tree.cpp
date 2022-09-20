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
    int res = 0;
    
    int getHeight(TreeNode* node, int height)
    {
        if (node == NULL)
            return height;
        
        return max(getHeight(node->left, height+1), getHeight(node->right, height+1));
    }
    
    void rec(TreeNode* node)
    {
        if (node == NULL)
            return;
        if (getHeight(node->left,0) + getHeight(node->right,0) > res)
            res = getHeight(node->left,0) + getHeight(node->right,0);
        
        rec(node->left);
        rec(node->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        rec(root);
        
        return res;
    }
};