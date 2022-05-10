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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        vector<TreeNode*> queue;
        if (root)
            queue.push_back(root);
        
        while (queue.size())
        {
            int n = queue.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                if (queue[0]->left)
                    queue.push_back(queue[0]->left);
                if (queue[0]->right)
                    queue.push_back(queue[0]->right);
                v.push_back(queue[0]->val);
                queue.erase(queue.begin());
            }
            res.push_back(v);
        }
        
        return res;
    }
};