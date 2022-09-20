class Solution {
public:
    string say(string s)
    {
        string saying = "";
        int idx = 0;
        
        while (idx < s.length())
        {
            int i = 1;
            while (s[idx+1] == s[idx++])
                i++;
            saying += to_string(i);
            
            cout << idx-1 << ": " << s[idx-1] << endl;
            saying += s[idx-1];
        }
        
        cout << "Saying: " << saying << endl;
        return saying;
    }
    
    string countAndSay(int n) {
        
        string res = "1";
        
        while (n-- > 1)
        {
            res = say(res);
        }
        
        return res;
    }
};