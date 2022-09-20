class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        vector<pair<int,int>> mp;
        size_t f,s,n;
        n = nums.size();
        int sum;
        
        for (int i = 0; i < n; i++)
            mp.push_back(make_pair(nums[i],i));
        sort(mp.begin(), mp.end());

        f = 0;
        s = n-1;
        sum = mp[f].first + mp[s].first;
        
        while (sum != target)
        {
            if (sum < target)
                f++;
            else if (sum > target)
                s--;

            sum = mp[f].first + mp[s].first;
        }
        
        res.push_back(mp[f].second); 
        res.push_back(mp[s].second);
        
        return res;
    }
};