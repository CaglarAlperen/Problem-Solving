class Solution {
public:
    int getSum(int a, int b) {
        
        int c = 0;
        int r = 0;
        int res = 0;
        
        for (int i = 0; i < sizeof(int) * 8; i++)
        {
            r = (a & 1) ^ (b & 1) ^ c;
            res = res | (r << i);
            
            if ( (a & 1) && (b & 1) )
                c = 1;
            else if ( ((a & 1) ^ (b & 1)) && c )
                c = 1;
            else 
                c = 0;
            
            a = a >> 1;
            b = b >> 1;
        }
        
        return res;
    }
};