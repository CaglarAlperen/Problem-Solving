class Solution {
public:
    bool isAnagram(string s1, string s2)
    {
        unordered_multiset<char> s;
        for (char c : s1)
            s.insert(c);
        for (char c : s2)
        {
            auto it = s.find(c);
            if (it != s.end())
                s.erase(it);
            else
                return false;
        }
        if (s.size() != 0)
            return false;
        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        
        bool removed = true;
        
        while (removed)
        {
            removed = false;
            
            for (int i = 1; i < words.size(); i++)
            {
                if (isAnagram(words[i],words[i-1]))
                {
                    words.erase(words.begin()+i--);
                    removed = true;
                }
            }
        }
        return words;
    }
};