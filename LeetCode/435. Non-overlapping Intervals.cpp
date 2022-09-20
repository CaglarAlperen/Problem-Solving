class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int res = 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int r = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < r)
            {
                res++;
                r = min(r, intervals[i][1]);
            }
            else 
            {
                r = intervals[i][1];
            }
        }
        
        return res;
    }
};