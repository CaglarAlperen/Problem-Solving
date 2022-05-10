class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> m;
        for (int i : nums)
            m[i]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto const& [key,val] : m)
        {
            pq.push(make_pair(val, key));
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};