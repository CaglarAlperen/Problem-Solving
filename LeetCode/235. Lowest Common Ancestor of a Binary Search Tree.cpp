/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool pe, qe;
    
    bool contain(TreeNode* root, int p, int q)
    {
        if (pe && qe)
            return true;
        if (!root)
            return false;
        if (root->val == p)
            pe = true;
        if (root->val == q)
            qe = true;
        return contain(root->left, p, q) || contain(root->right, p, q);
    }
    
    TreeNode* res;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root)
            return res;
        pe = false;
        qe = false;
        if (contain(root, p->val, q->val))
            res = root; 
        lowestCommonAncestor(root->left, p, q);
        lowestCommonAncestor(root->right, p, q);
        return res;
    }
};