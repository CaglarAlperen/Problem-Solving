class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int allXOR = 0;
        
        for (int i : nums)
        {
            allXOR ^= i;
        }
        
        return allXOR;
    }
};