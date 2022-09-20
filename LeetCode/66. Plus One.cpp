class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int i = digits.size() - 1;
        
        digits[i]++;
        if (digits[i] == 10)
        {
            digits[i--] = 0;
            while (i >= 0)
            {
                digits[i]++;
                if (digits[i] != 10)
                    break;
                else
                    digits[i] = 0;
                i--;
            }
            if (i == -1)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        
        return digits;
    }
};