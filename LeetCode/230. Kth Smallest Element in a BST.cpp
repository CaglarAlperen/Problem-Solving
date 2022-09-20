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
    int rank = 1;
    int res;
    
    void helper(TreeNode* root, int k)
    {
        if (!root)
            return;
        
        if (!root->left && !root->right)
        {
            if (rank++ == k)
                res = root->val;
            return;
        }
        else
        {
            int left = kthSmallest(root->left, k);
            if (left != -1)
                res = left;
            
            if (rank++ == k)
                res = root->val;
            
            int right = kthSmallest(root->right, k);
            if (right != -1)
                res = right;
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        helper(root, k);
        
        return res;
    }
};