class Solution {
public:
    int romanToInt(string s) {
        
        int val = 0;
        int len = s.length();
            
        for (int i = 0; i < len; i++)
        {
            if (Roman(s[i]) < Roman(s[i+1]))
            {
                val -= Roman(s[i]);
            }
            else {
                val += Roman(s[i]);
            }
        }
        
        return val;
    }
    
    int Roman(char c)
    {
        switch (c)
        {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }
};