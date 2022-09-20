class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int res = 0;
        
        for (int i = 31; i > -1; i--)
        {
            res += (n & 1) << i;
            n = n >> 1;
        }
        
        return res;
    }
};