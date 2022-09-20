class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> res;
        
        for (int i = 0; i <= n; i++)
        {
            res.push_back(count1(i));
        }
        
        return res;
    }
    
    int count1(int n)
    {
        int res = 0;
        while (n > 0)
        {
            res += n & 1;
            n = n >> 1;
        }
        return res;
    }
};