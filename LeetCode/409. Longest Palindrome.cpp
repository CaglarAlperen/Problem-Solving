class Solution {
public:
    int longestPalindrome(string s) 
    {
        map<char, int> m;
        
        for (char c : s)
        {
            m[c]++;
        }
        
        int len = 0;
        bool hasSingle = false;
        
        for (auto const& [key, value] : m)
        {
            if (value%2 == 1 && !hasSingle)
            {
                len += value;
                hasSingle = true;
            }
            else
            {
                len += value - value%2;
            }
        }
        
        return len;
    }
};