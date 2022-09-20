class Solution {
public:
    vector<string> getLetters(char c)
    {
        vector<vector<string>> table = { {"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"} };
        
        return table[c-50];
    }
    
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        
        for (char digit : digits)
        {
            int size = res.size();
            vector<string> letters = getLetters(digit);
            
            if (size == 0)
            {
                for (string s : letters)
                {
                    res.push_back(s);
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    string str = res[i];
                    for (string s : letters)
                    {
                        res.push_back(str + s);
                    }
                }
            }
            
            for (int i = 0; i < size; i++)
                res.erase(res.begin());
        }
        
        return res;
    }
};