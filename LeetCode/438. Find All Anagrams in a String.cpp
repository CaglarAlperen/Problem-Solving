class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char, int> m;
        for (char c : p)
        {
            m[c]++;
        }
        int diff = p.length();
        
        int l = 0, r = 0;
        for (int i = 0; i < p.length(); i++)
        {
            if (m[s[r]] > 0)
                diff--;
            else
                diff++;
            m[s[r++]]--;
        }
        r--;
        vector<int> res;
        
        while (r < s.length())
        {
            if (diff == 0)
                res.push_back(l);
            
            if (m[s[l]] < 0)
                diff--;
            else
                diff++;
            m[s[l++]]++;
            if (m[s[r+1]] > 0)
                diff--;
            else
                diff++;
            m[s[++r]]--;
        }
        
        return res;
    }
};