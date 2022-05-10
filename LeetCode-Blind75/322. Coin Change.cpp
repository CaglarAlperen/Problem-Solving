class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int D[amount+1];
        int len = coins.size();
        int s = 0;
        
        D[0] = 0;
        
        for (int i = 1; i < amount+1; i++)
        {
            int _min = 1e9;
            for (int coin : coins)
            {
                if (i >= coin)
                    _min = min(_min, D[i-coin] + 1);
            }
            D[i] = _min;
        }
        
        return (D[amount] == 1e9) ? -1 : D[amount];
    }
};