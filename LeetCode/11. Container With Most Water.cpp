class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int len = height.size();
        int l = 0, r = len-1;
        int area = min(height[l], height[r]) * (r-l);
        
        bool changed = true;
        
        while (changed)
        {
            if (l >= len-2) break;
            if (r <= 1) break;
            changed = false;
            
            if (height[l] < height[r])
            {
                while (l < len-3 && height[l+1] <= height[l])
                    l++;
                l++;
                changed = true;
            }
            else 
            {
                while (r > 2 && height[r-1] <= height[r])
                    r--;
                r--;
                changed = true;
            }
            
            if (min(height[l], height[r]) * (r-l) > area)
                area = min(height[l], height[r]) * (r-l);
        }
        
        return area;
    }
};