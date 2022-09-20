class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        multimap<int, vector<int>, less<int>> m;
        
        for (vector<int> point : points)
        {
            int dist = 0;
            dist += point[0] * point[0];
            dist += point[1] * point[1];
            m.insert(pair<int, vector<int>>(dist, point));
        }
        
        vector<vector<int>> res;

        for (auto const& [key, value] : m)
        {
            if (k == 0)
                break;
            res.push_back(value);
            k--;
        }
        
        return res;
    }
};