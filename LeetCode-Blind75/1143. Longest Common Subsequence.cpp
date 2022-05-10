class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        int D[n+1][m+1];
        
        memset(D, 0, (n+1) * (m+1) * sizeof(int));
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i-1] == text2[j-1])
                    D[i][j] = D[i-1][j-1] + 1;
                else 
                    D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
        
        return D[n][m];
    }
};