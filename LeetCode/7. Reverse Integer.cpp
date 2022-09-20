class Solution {
public:
    int reverse(int x) {
        
        string s = to_string(x);
        int negate = (s[0] == '-') ? -1 : 1;
        if (negate == -1)
            s = s.substr(1,s.length()-1);
        std::reverse(s.begin(), s.end());
        long reversed = stol(s) * negate;
        if (reversed > INT_MAX || reversed < INT_MIN)
            return 0;
        
        return reversed;
    }
};