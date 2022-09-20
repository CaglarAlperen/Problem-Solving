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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == NULL)
            return {};
        
        vector<int> res;

        vector<TreeNode*> queue = {root};
        
        while (queue.size())
        {
            res.push_back(queue[queue.size()-1]->val);
            
            int size = queue.size();
            
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = queue[i];
                if (node->left)
                    queue.push_back(node->left);
                if (node->right)
                    queue.push_back(node->right);
            }
            
            for (int i = 0; i < size; i++)
                queue.erase(queue.begin());
        }
        
        return res;
    }
};