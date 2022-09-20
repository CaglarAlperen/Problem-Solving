class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        char max;
        int max_val = 0;
        
        map<char, int> m;
        for (char c : tasks)
        {
            m[c]++;
            if (m[c] > max_val)
            {
                max_val = m[c];
                max = c;
            }
        }
        
        int need = (m[max]-1) * n;
        
        for (auto const &[key, value] : m)
        {
            if (key == max)
                continue;
            need -= min(value, m[max]-1);
        }
        
        return tasks.size() + (need > 0 ? need : 0);
    }
};