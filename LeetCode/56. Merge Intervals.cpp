class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int l = intervals[0][0];
        int r = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > r)
            {
                res.push_back(vector<int>{l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else
            {
                l = min(l,intervals[i][0]);
                r = max(r,intervals[i][1]);
            }
        }
        
        res.push_back(vector<int>{l,r});
        
        return res;
    }
};