class Solution {
public:
    string format(string s)
    {
        string res = "";
        
        for (char c : s)
        {
            if (c >= 65 && c <= 90)
            {
                res += c+32;
            }
            else if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57))
            {
                res += c;
            }
        }
        
        return res;
    }
    
    bool isPalindrome(string s) {
        
        s = format(s);
        int len = s.length();
        
        for (int i = 0; i < len/2; i++)
        {
            if (s[i] != s[len-1-i])
                return false;
        }
        
        return true;
    }
};