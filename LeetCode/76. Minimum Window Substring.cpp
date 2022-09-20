class Solution {
public:
    bool contain(unordered_map<char, int> m)
    {
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > 0)
            {
                return false;
            }       
        }
        return true;
    }
    
    string minWindow(string s, string t) {
    
        unordered_map<char, int> m;
        int min_l = 0, min_r = 1e6;
        int l = 0, r = 0;
        bool cnt = false;
        
        for (int i = 0; i < t.length(); i++)
        {
            m[t[i]]++;
        }
        
        if (m.find(s[0]) != m.end())
        {
            m[s[0]]--;
            if (m[s[0]] > 0)
                cnt = false;
            else 
                cnt = contain(m);
        }
            
        
        while(r < s.length())
        {
            if (cnt)
            {
                if (r - l < min_r - min_l)
                {
                    min_r = r;
                    min_l = l;
                }
                if (m.find(s[l]) != m.end())
                {
                    m[s[l]]++;
                    if (m[s[l]] > 0)
                        cnt = false;
                }
                l++;
            }
            else 
            {
                r++;
                if (m.find(s[r]) != m.end())
                {
                    m[s[r]]--;
                    if (m[s[r]] > 0)
                        cnt = false;
                    else
                        cnt = contain(m);
                }
            }
        }
        
        if (min_r == 1e6)
            return "";
        
        return s.substr(min_l, min_r - min_l + 1);
    }
};