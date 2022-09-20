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
    bool helper(TreeNode* root, long min, long max)
    {
        if (!root)
            return true;
        if (root->left)
            if (root->left->val >= root->val || root->left->val <= min)
                return false;
        if (root->right)
            if (root->right->val <= root->val || root->right->val >= max)
                return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, -2147483649, 2147483648);
    }
};