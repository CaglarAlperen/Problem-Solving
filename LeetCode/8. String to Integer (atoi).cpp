class Solution {
public:
    string read_digits(int i, string s)
    {
        string digits = "";
        while (s[i] > 47 && s[i] < 58)
        {
            digits += s[i++];
        }
        return digits;
    }
    
    int myAtoi(string s) {
        
        int negate = 0;
        bool has_digits = false;
        string digits;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (negate != 0)
                    return 0;
                continue;
            }
            else if (s[i] == '+')
            {
                if (negate != 0)
                    return 0;
                negate = 1;
            }
            else if (s[i] == '-')
            {
                if (negate != 0)
                    return 0;
                negate = -1;
            }
            else if (s[i] > 47 && s[i] < 58)
            {
                digits = read_digits(i, s);
                has_digits = true;
                break;
            }
            else
            {
                return 0;
            }
        }
        
        if (!has_digits)
            return 0;
        
        if (negate == 0)
            negate = 1;
        
        long value = digits[0] - 48;
        for (int i = 1; i < digits.length(); i++)
        {
            value *= 10;
            value += digits[i] - 48;
            if (value > INT_MAX)
            {
                if (negate == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }
        return value * negate;
    }
};