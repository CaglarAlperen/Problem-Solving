class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = 0; i < n; i++)
        {
            nums1.erase(nums1.end()-1);
        }
        
        for (int i = 0; i < n; i++)
        {
            nums1.insert(lower_bound(nums1.begin(), nums1.end(), nums2[i]), nums2[i]);
        }
        
    }
};