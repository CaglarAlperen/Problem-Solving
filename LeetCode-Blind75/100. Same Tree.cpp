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
    void list(TreeNode* root, vector<int> &v)
    {
        vector<TreeNode*> nodes;
        if (root)
            nodes.push_back(root);
        
        while (nodes.size())
        {
            int n = nodes.size();
            for (int i = 0; i < n; i++)
            {
                if (nodes[0])
                {
                    nodes.push_back(nodes[0]->left);
                    nodes.push_back(nodes[0]->right);    
                    v.push_back(nodes[0]->val);
                }
                else
                    v.push_back(1e5);
                nodes.erase(nodes.begin());
            }
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        vector<int> pv;
        vector<int> qv;
        
        list(p, pv);
        list(q, qv);
        
        if (pv.size() != qv.size())
            return false;
        
        for (int i = 0; i < pv.size(); i++)
        {
            if (pv[i] != qv[i])
                return false;
        }
        
        return true;
    }
};