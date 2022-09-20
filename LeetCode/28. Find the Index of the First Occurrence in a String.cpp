class Solution {
public:
    bool test(string haystack, string needle, int k)
    {
        for (int i = 0; i < needle.length(); i++)
        {
            if (haystack[k+i] != needle[i])
                return false;
        }
        
        return true;
    }
    
    int strStr(string haystack, string needle) {
        
        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0])
            {
                if(test(haystack, needle, i))
                    return i;
            }
        }
        
        return -1;
    }
};