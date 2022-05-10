class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        for (int num : nums)
            s.insert(num);
        int res = 0;
        for (int n : nums)
        {
            int len = 1;
            if (s.find(n-1) == s.end())
            {
                s.erase(n);
                while (s.find(n+1) != s.end())
                {
                    len++;
                    s.erase(n+1);
                    n++;
                }
                    
                if (len > res) res = len;
            }
        }
            
        return res;
    }
};