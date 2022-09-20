class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int arr[123];
        memset(arr, 0, 123*sizeof(int));
        
        for (char c : s)
            arr[c]++;
        for (char c : t)
            arr[c]--;
        for (int i = 65; i < 123; i++)
            if (arr[i] != 0)
                return false;
        return true; 
    }
};