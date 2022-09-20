class Solution {
public:
    double myPow(double x, int n) 
    {
        double res = 1;
        double tmp = x;
        
        long ln = n;
        long exp = 1;
        
        if (ln < 0)
        {
            x = 1/x;
            tmp = 1/tmp;
            ln = -ln;
        }
        
        double init_val = tmp;
        
        if (ln == 0)
            return 1;
        
        if (x == 1.0)
            return 1.0;
        
        if (x == -1.0)
            return ln%2 ? -1.0 : 1.0;
        
        while (ln > 0)
        {
            while (exp <= ln/2)
            {
                tmp *= tmp;
                exp *= 2;
            }
            cout << "exp: " << exp << " res: " << res << " tmp: " << tmp << endl;
            ln -= exp;
            res *= tmp;
            exp = 1;
            tmp = init_val;
        }
        
        return res;
    }
};