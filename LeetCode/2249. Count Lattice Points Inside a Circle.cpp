class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        set<pair<int,int>> s;
        
        for (vector<int> v : circles)
        {
            int x = v[0];
            int y = v[1];
            int r = v[2];
            
            for (int i = x-r; i <= x+r; i++)
            {
                for (int j = y-r; j <= y+r; j++)
                {
                    if ((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
                    {
                        s.insert(make_pair(i,j));
                    }
                }
            }
        }
        
        return s.size();
    }
};