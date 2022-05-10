class Solution {
public:   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        
        bool P[n][m];
        bool A[n][m];
        memset(P, 0, n*m*sizeof(bool));
        memset(A, 0, n*m*sizeof(bool));

        bool changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (P[i][j])
                        continue;
                    if (i == 0 || j == 0)
                    {
                        P[i][j] = true;
                    }
                    else
                    {
                        if (i < n-1)
                        {
                            if ( P[i+1][j] && heights[i+1][j] <= heights[i][j] )
                            {
                                P[i][j] = true;
                                changed = true;
                            }
                        }
                        if (j < m-1)
                        {
                            if ( P[i][j+1] && heights[i][j+1] <= heights[i][j] )
                            {
                                P[i][j] = true;
                                changed = true;
                            }
                        }
                        if ( (P[i-1][j] && heights[i-1][j] <= heights[i][j]) 
                            || (P[i][j-1] && heights[i][j-1] <= heights[i][j]))
                        {
                            P[i][j] = true;
                            changed = true;
                        }
                    }
                }
            }
        }
        changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (A[i][j])
                        continue;
                    if (i == n-1 || j == m-1)
                    {
                        A[i][j] = true;
                        changed = true;
                    }
                    else
                    {
                        if (i > 0)
                        {
                            if ( A[i-1][j] && heights[i-1][j] <= heights[i][j] )
                            {
                                A[i][j] = true;
                                changed = true;
                            }
                        }
                        if (j > 0)
                        {
                            if ( A[i][j-1] && heights[i][j-1] <= heights[i][j] )
                            {
                                A[i][j] = true;
                                changed = true;
                            }
                        }
                        if ( (A[i+1][j] && heights[i+1][j] <= heights[i][j]) 
                            || (A[i][j+1] && heights[i][j+1] <= heights[i][j] ) )
                        {
                            A[i][j] = true;
                            changed = true;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << P[i][j] << "," << A[i][j] << " ";
                if (P[i][j] && A[i][j])
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    res.push_back(v);
                }
            }
            cout << endl;
        }
        
        return res;
    }
};