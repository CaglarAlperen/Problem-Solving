class Solution {
public:
    int numDecodings(string s) {
        
        int len = s.length();
        int D[len+1];
        memset(D, 0, (len+1)*sizeof(int));
        D[len] = 1;
        D[len-1] = (s[len-1] == '0') ? 0 : 1;
        
        for (int i = len - 2; i >= 0; i--)
        {
            if (s[i] > '2' && s[i+1] == '0')
                return 0;
            if ( s[i] == '1' || (s[i] == '2' && s[i+1] < '7') )
                D[i] = D[i+1] + D[i+2];
            else if (s[i] == '0')
                D[i] = 0;
            else if (s[i+1] == '0')
                D[i] = D[i+2];
            else
                D[i] = D[i+1];
        }
        
        return D[0];
    }
};