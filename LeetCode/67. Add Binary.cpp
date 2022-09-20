class Solution {
public:
    string addBinary(string a, string b) 
    {
        string res = "";
        
        int i = a.length()-1, j = b.length()-1;
        bool carry = false;
        
        while (i >= 0 && j >= 0)
        {
            char sum = (a[i]-48) ^ (b[j]-48) ^ carry + 48;
            res.insert(res.begin(), sum);
            carry = a[i]-48 + b[j]-48 + (carry ? 1 : 0) > 1;
            i--; j--;
        }
        while (i >= 0)
        {
            char sum = (a[i]-48) ^ carry + 48;
            res.insert(res.begin(), sum);
            carry = a[i]-48 + (carry ? 1 : 0) > 1;
            i--;
        }
        while (j >= 0)
        {
            char sum = (b[j]-48) ^ carry + 48;
            res.insert(res.begin(), sum);
            carry = b[j]-48 + (carry ? 1 : 0) > 1;
            j--;
        }
        if (carry)
        {
            res.insert(res.begin(), '1');
        }
        
        return res;
    }
};