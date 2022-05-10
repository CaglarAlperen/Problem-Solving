class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l=0,r=0;
        int max_len = 0;
        int size = s.length();
        set<char> set;
        
        while (l < size && r < size)
        {
            if (find(set.begin(), set.end(), s[r]) != set.end())
            {
                set.erase(s[l]);
                l++;
            }
            else {
                set.insert(s[r]);
                r++;
                if (r-l > max_len)
                {
                    max_len = r-l;
                }
            }
        }
        
        return max_len;
    }
};