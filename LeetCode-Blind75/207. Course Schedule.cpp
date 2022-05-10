class Solution {
public:    
    bool dfs(int i, vector<int> P[], bool V[], int n)
    {
        if (P[i].size() == 0)
            return true;
        if (V[i])
            return false;
        
        V[i] = true;
        
        bool res = true;
        
        for (int pre : P[i])
        {
            res = res && dfs(pre, P, V, n);
            V[pre] = false;
        }
        
        if (res) P[i].clear();
        return res;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> P[numCourses];
        bool V[numCourses];
        
        for (int i = 0; i < numCourses; i++)
            V[i] = false;
        
        for (vector<int> v : prerequisites)
            P[v[0]].push_back(v[1]);
                
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, P, V, numCourses))
                return false;
            for (int i = 0; i < numCourses; i++)
                V[i] = false;
        }
        
        return true;
    }
};