/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (node == NULL)
            return NULL;
        
        map<Node*, Node*> hm;
        vector<int> visited;
        vector<Node*> queue;
        queue.push_back(node);
        
        while (queue.size() > 0)
        {
            Node *n = queue[0];
            hm[n] = new Node(n->val);
            visited.push_back(n->val);
            
            for (Node *neighbor : n->neighbors)
            {
                if (find(visited.begin(), visited.end(), neighbor->val) == visited.end())
                {
                    queue.push_back(neighbor);
                    hm[neighbor] = new Node(neighbor->val);
                    visited.push_back(neighbor->val);
                }
            }
            queue.erase(queue.begin());
        }
        
        for (auto it = hm.begin(); it != hm.end(); it++)
        {
            for (Node *n : it->first->neighbors)
            {
                it->second->neighbors.push_back(hm[n]);
            }
        }
        
        return hm[node];
    }
};