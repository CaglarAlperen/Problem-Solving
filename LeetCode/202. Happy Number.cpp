class Solution {
public:
    int digitSquares(int n)
    {
        int val = 0;
        string s = to_string(n);
        for (int i = 0; i < s.length(); i++)
        {
            val += (s[i] - 48) * (s[i] - 48);
        }
        return val;
    }
    
    bool isHappy(int n) {
        
        set<int> prevValues;
        
        while (n != 1)
        {
            prevValues.insert(n);
            n = digitSquares(n);
            if (prevValues.find(n) != prevValues.end())
                return false;
        }
        
        return true;
    }
};