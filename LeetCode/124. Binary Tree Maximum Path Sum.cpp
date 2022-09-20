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
    int res = -1001;
    
    int helper(TreeNode* root)
    {
        if (!root)
            return 0;
        
        if (root->val >= 0)
        {
            int lval = helper(root->left);
            int rval = helper(root->right);
            int val = max(lval, rval) + root->val;
            if (val > res)
            {
                res = val;
            }
            if (root->val > res)
            {
                res = root->val;
            }
            if (lval + rval + root->val > res)
            {
                res = lval + rval + root->val;
            }
            return max(val, root->val);
        }
        else 
        {
            int lval,rval;
            if (!root->left)
                lval = -1001;
            else 
                lval = helper(root->left);
            if (!root->right)
                rval = -1001;
            else
                rval = helper(root->right);
            int val = max(lval, rval);
            if (val > res)
            {
                res = val;
            }
            if (root->val > res)
            {
                res = root->val;
            }
            if (lval + rval + root->val > res)
            {
                res = lval + rval + root->val;
            }
            return max(val + root->val, root->val);
        }
    }
    
    int maxPathSum(TreeNode* root) {
        
        helper(root);
        
        return res;
    }
};