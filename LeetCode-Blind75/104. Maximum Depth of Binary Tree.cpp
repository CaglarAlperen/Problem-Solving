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
    int maxDepth(TreeNode* root) {
        
        int res = 0;
        vector<TreeNode*> nodes;
        if (root)
            nodes.push_back(root);
        
        while (nodes.size())
        {
            res++;
            int n = nodes.size();
            for (int i = 0; i < n; i++)
            {
                if (nodes[0]->left)
                    nodes.push_back(nodes[0]->left);
                if (nodes[0]->right)
                    nodes.push_back(nodes[0]->right);
                nodes.erase(nodes.begin());
            }
        }
        
        return res;
    }
};