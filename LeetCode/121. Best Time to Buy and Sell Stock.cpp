class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int len = prices.size();
        int min = prices[0];

        for (int i = 1; i < len; i++)
        {
            if (prices[i] < min) min = prices[i];
            if (prices[i] > min)
            {
                if (prices[i] - min > profit)
                    profit = prices[i] - min;
            }
        }
        
        return profit;
    }
};