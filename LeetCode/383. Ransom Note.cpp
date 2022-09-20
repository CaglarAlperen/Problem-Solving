class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char, int> magazineMap;
        
        for (char c : magazine)
        {
            magazineMap[c]++;
        }
        
        for (char c : ransomNote)
        {
            if (magazineMap[c] == 0)
                return false;
            magazineMap[c]--;
        }
        
        return true;
    }
};