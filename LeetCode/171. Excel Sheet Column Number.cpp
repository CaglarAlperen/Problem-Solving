class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int val = 0;
        int len = columnTitle.length();
        for (int i = 0; i < len; i++)
        {
            val += (columnTitle[i] - 64) * pow(26, len-i-1);
        }
        
        return val;
    }
};