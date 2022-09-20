class Solution {
public:
    set<string> res;
    
    void rec(string s, int n, bool left, int l_count, int r_count)
    {
        if (s.length() == 2*n)
        {
            if (l_count == r_count)
                res.insert(s);     
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (s.length() + i > 2*n)
                return;
            if (!left && r_count + i > l_count)
                return;
            string append(i, left ? '(' : ')');
            l_count += left ? i : 0;
            r_count += left ? 0 : i;
            s += append;
            rec(s, n, !left, l_count, r_count);
            s.erase(s.end() - i, s.end());
            l_count -= left ? i : 0;
            r_count -= left ? 0 : i;
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        rec("", n, true, 0, 0);
        vector<string> ret(res.begin(), res.end());
        return ret;
    }
};