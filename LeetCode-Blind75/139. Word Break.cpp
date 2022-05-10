class Solution {
public:
    bool check(string s, string a)
    {
        if (s.length() < a.length())
            return false;
        for (int i = 0; i < a.length(); i++)
        {
            if (s[i] != a[i])
                return false;
        }
        return true;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.length();
        bool D[len];
        memset(D, 0, len * sizeof(bool));
        
        for (int i = len-1; i >= 0; i--)
        {
            bool exist = false;
            for (string str : wordDict)
            {
                if (check(s.substr(i, len - i), str))
                {
                    if (i + str.length() == len) 
                        D[i] = true;
                    else 
                        D[i] = max(D[i], D[i+str.length()]);
                    exist = true;
                }
            }
            if (!exist)
            {
                D[i] = false;
            }
        }
        
        return D[0];
    }
};