class Solution {
public:
    bool invalid(unordered_map<char, int> m, int k)
    {
        int sum = 0;
        int max = 0;
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            sum += it->second;
            if (it->second > max)
                max = it->second;
        }
        
        if (sum - max > k)
            return true;
        return false;
    }
    
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> m;
        int res = 0;
        int l = 0, r = 1;
        
        m[s[l]]++;
        m[s[r]]++;
        while (r < s.length())
        {
            if (!invalid(m,k))
            {
                res = max(res, r-l+1);
                r++;
                m[s[r]]++;
            }
            else 
            {
                while (invalid(m,k))
                {
                    m[s[l]]--;
                    l++;
                }
            }
        }

        return res;
    }
};