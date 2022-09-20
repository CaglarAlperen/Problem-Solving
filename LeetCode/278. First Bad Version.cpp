// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long l = 1, r = n;
        
        while (l < r-1)
        {
            long mid = (l+r)/2;
            
            if (isBadVersion(mid))
            {
                if (!isBadVersion(mid-1))
                {
                    return mid;
                }
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        
        if (isBadVersion(l))
            return l;
        else
            return r;
    }
};