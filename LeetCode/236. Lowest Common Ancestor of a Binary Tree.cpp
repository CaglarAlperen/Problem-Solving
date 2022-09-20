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
    void find(TreeNode* root, TreeNode* p, TreeNode* q, int& count)
    {
        if (root == NULL)
        {
            return;
        }
        if (root == p || root == q)
        {
            count++;
        }
        
        find(root->left, p, q, count);
        find(root->right, p, q, count);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {       
        if (root == p)
        {
            return p;
        }
        else if (root == q)
        {
            return q;
        }
        
        int count = 0;
        find(root->left, p, q, count);
        
        if (count == 1)
        {
            return root;
        }
        else if (count == 2)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};