class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        bool DP[n][n];
        memset(DP, 0, n*n*sizeof(bool));
        int res = 0;
        
        for (int sz = 0; sz < n; sz++)
        {
            for (int i = 0; i+sz < n; i++)
            {
                if (sz == 0)
                {
                    DP[i][i] = 1;
                    res++;
                }
                else if (sz == 1)
                {
                    DP[i][i+1] = s[i] == s[i+1];
                    if (DP[i][i+1])
                        res++;
                }
                else 
                {
                    DP[i][i+sz] = DP[i+1][i+sz-1] && s[i] == s[i+sz];
                    if (DP[i][i+sz])
                        res++;
                }
            }    
        }
        
        return res;
    }
};