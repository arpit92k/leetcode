class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l = prices.size();
        if(l > 0)
        {
            int min_price = prices[0];
            int profit;
            int i = 1;
            while(i<l)
            {
                profit = prices[i] - min_price;
                max_profit = profit > max_profit ? profit : max_profit;
                min_price = prices[i] < min_price ? prices[i] : min_price;
                ++i;
            }
        }
        return max_profit;
        
    }
};
