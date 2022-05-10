class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        
        int prefix[len];
        int postfix[len];
        
        prefix[0] = nums[0];
        postfix[len-1] = nums[len-1];
        for (int i = 1, j = len-2; i < len; i++, j--)
        {
            prefix[i] = prefix[i-1] * nums[i];
            postfix[j] = postfix[j+1] * nums[j];
        }
            
        vector<int> res;
        
        for (int i = 0; i < len; i++)
        {
            if (i == 0) 
                res.push_back(postfix[i+1]);
            else if (i == len-1)
                res.push_back(prefix[i-1]);
            else 
                res.push_back(prefix[i-1] * postfix[i+1]);
        }
        
        return res;
    }
};