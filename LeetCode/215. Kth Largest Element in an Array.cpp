class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        map<int, int> m;
        
        for (int i : nums)
            m[i]++;
        
        for (auto it = m.rbegin(); it != m.rend(); it++)
        {
            k -= it->second;
            if (k <= 0)
                return it->first;
        }
        
        return -1;
    }
};