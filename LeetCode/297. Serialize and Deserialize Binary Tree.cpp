/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string data = "";
        vector<TreeNode*> queue;
        if (root)
            queue.push_back(root);
        while (queue.size())
        {
            int n = queue.size();
            for (int i = 0; i < n; i++)
            {
                if (queue[0])
                {
                    queue.push_back(queue[0]->left);
                    queue.push_back(queue[0]->right);
                }
                if (queue[0])
                    data += to_string(queue[0]->val) + ",";
                else 
                    data += "n,";
                queue.erase(queue.begin());
            }
        }
    
        return data;
    }
    
    TreeNode* extract(string s)
    {
        if (s == "n")
            return NULL;
        else 
            return new TreeNode(stoi(s));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    
        if (data.length() == 0)
            return NULL;
        
        TreeNode* root = NULL;
        vector<TreeNode*> queue;
        int delim;
        string element;
        
        delim = data.find(",");
        element = data.substr(0,delim);
        data = data.substr(delim+1,data.length()-delim-1);

        queue.push_back(extract(element));
        root = queue[0];
        
        while (data.length())
        {
            int n = queue.size();
            for (int i = 0; i < 2*n; i++)
            {
                delim = data.find(",");
                element = data.substr(0,delim);
                data = data.substr(delim+1,data.length()-delim-1);
                
                TreeNode *node = extract(element);    
                if (i%2)
                    queue[i/2]->right = node;
                else
                    queue[i/2]->left = node;
                
                if (node)
                    queue.push_back(node);
            }
            for (int i = 0; i < n; i++)
                queue.erase(queue.begin());
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));