class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        
        int l = newInterval[0];
        int r = newInterval[1];
        
        int indx = 0;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
                indx++;
            }
            else if (intervals[i][0] > newInterval[1])
            {
                res.push_back(intervals[i]);
            }
            else 
            {
                l = min(l,min(intervals[i][0], newInterval[0]));
                r = max(r,max(intervals[i][1], newInterval[1]));
            }
        }
        vector<int> nw;
        nw.push_back(l);
        nw.push_back(r);
        
        res.insert(res.begin() + indx, nw);
        
        return res;
    }
};