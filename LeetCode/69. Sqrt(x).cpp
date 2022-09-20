class Solution {
public:
    int mySqrt(int x) {
        
        long sum = 1;
        int step = 3;
        int res = 0;
        
        while (sum <= x)
        {
            sum += step;
            step += 2;
            res++;
        }
        
        return res;
    }
};