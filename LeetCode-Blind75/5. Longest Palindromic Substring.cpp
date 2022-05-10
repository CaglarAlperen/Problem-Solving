class Solution {
public:
    string longestPalindrome(string s) {
     
        int n = s.length();
        bool DP[n][n];
        memset(DP, 0, n*n*sizeof(bool));
        int ridx, rlen=0;
        
        for (int sz = 0; sz < n; sz++)
        {
            for (int i = 0; i+sz < n; i++)
            {
                if (sz == 0)
                {
                    DP[i][i+sz] = 1;
                    if (sz+1 > rlen)
                    {
                        ridx = i;
                        rlen = sz+1;
                    }
                }  
                else if (sz == 1)
                {
                    DP[i][i+1] = s[i] == s[i+1];
                    if (DP[i][i+1] && sz+1 > rlen)
                    {
                        ridx = i;
                        rlen = sz+1;
                    }
                }
                else
                {
                    DP[i][i+sz] = DP[i+1][i+sz-1] && s[i] == s[i+sz];
                    if (DP[i][i+sz] && sz+1 > rlen)
                    {
                        ridx = i;
                        rlen = sz+1;
                    }
                }
            }
        }
        
        return s.substr(ridx, rlen);
    }
};