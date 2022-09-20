class Solution {
public: 
    unordered_map<string, vector<int>> graph;
    unordered_map<string, bool> visited;
    vector<vector<string>> res;
    
    void util(string key, vector<vector<string>> accounts, vector<string> &component)
    {
        vector<int> queue;
        for (int i : graph[key])
            queue.push_back(i);
        component.push_back(accounts[queue[0]][0]);
        for (int i = 0; i < queue.size(); i++)
        {
            int idx = queue[i];
            for (int j = 1; j < accounts[idx].size(); j++)
            {
                if (!visited[accounts[idx][j]])
                {
                    visited[accounts[idx][j]] = true;
                    component.push_back(accounts[idx][j]);
                    for (int k : graph[accounts[idx][j]])
                        queue.push_back(k);
                }
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                graph[accounts[i][j]].push_back(i);
                visited[accounts[i][j]] = false;
            }
        }
        
        for (auto const &[key,value] : graph)
        {
            if (!visited[key])
            {
                vector<string> component;
                util(key, accounts, component);
                sort(component.begin()+1, component.end());
                res.push_back(component);
            }
        }
        
        return res;
    }
};