class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> m;
        vector<vector<string>> res;
        
        for (string s : strs)
        {
            vector<int> v(26,0);
            for (char c : s)
                v[c-97]++;
            m[v].push_back(s);
        }
        
        for (auto const &[key, val] : m)
        {
            res.push_back(val);
        }
        
        return res;
    }
};