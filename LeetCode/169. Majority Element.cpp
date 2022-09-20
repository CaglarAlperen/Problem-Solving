class Solution {
public:
    int majorityElement(vector<int>& nums) {
         
        map<int, int> m;
        int max = 0;
        int max_val = 0;
        for (int i : nums)
        {
            m[i]++;
            if (m[i] > max_val)
            {
                max_val = m[i];
                max = i;
            }
        }
        
        return max;
    }
};