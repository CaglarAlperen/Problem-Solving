class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        char c;
        string res = "";
        int len = strs.size();
        
        int j = 0;
        while (1)
        {
            if (strs[0].length() <= j) break;
            c = strs[0][j];
            for (int i = 0; i < len; i++)
            {
                if (strs[i].length() <= j) return res;
                if (strs[i][j] != c) return res;
            }
            
            res += c;
            j++;
        }
        
        return res;
    }
};