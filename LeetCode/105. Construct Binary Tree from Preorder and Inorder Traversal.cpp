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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                
        if (preorder.size() == 0)
            return NULL;
        if (preorder.size() == 1)
            return new TreeNode(preorder[0]);
        
        int rval = preorder[0];
        auto ridx = find(inorder.begin(), inorder.end(), rval);
        int dist = distance(inorder.begin(), ridx);
        
        TreeNode *root = new TreeNode(rval);
        
        vector<int> linorder(inorder.begin(), ridx);
        vector<int> rinorder(ridx+1, inorder.end());
        vector<int> lpreorder(preorder.begin()+1, preorder.begin()+dist+1);
        vector<int> rpreorder(preorder.begin()+dist+1, preorder.end());
        
        root->left = buildTree(lpreorder, linorder);
        root->right = buildTree(rpreorder, rinorder);
        
        return root;
    }
};