class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int len = 0;
        for (int i : endTime)
        {
            if (i > len)
                len = i;
        }

        vector<pair<int, int>> endTimeSorted;
        for (int i = 0; i < endTime.size(); i++)
        {
            endTimeSorted.push_back(make_pair(endTime[i],i));
        }
        sort(endTimeSorted.begin(), endTimeSorted.end());
            
        map<int, int> DP;
        DP[len+1] = 0;
        
        for (pair<int, int> p : endTimeSorted)
        {
            int start = startTime[p.second];
            int end = p.first;
            int prft = profit[p.second];
            
            auto endValIt = DP.lower_bound(end);
            int endVal = endValIt->first == end ? endValIt->second : (--endValIt)->second;
            auto startValIt = DP.lower_bound(start);
            int startVal = startValIt->first == start ? startValIt->second : (--startValIt)->second;
            DP[end] = max(endVal, startVal + prft);
        }
        
        return DP[len];
    }
};