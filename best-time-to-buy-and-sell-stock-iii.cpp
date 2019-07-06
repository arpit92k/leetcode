class Solution {
    int MaxProfit(vector<int>& prices, int s, int e) {
        int max_profit = 0;
        int l = prices.size();
        if(e - s > 0)
        {
            int min_price = prices[s];
            int profit;
            int i = s+1;
            while(i <= e)
            {
                profit = prices[i] - min_price;
                max_profit = profit > max_profit ? profit : max_profit;
                min_price = prices[i] < min_price ? prices[i] : min_price;
                ++i;
            }
        }
        return max_profit;    
    }
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        int max_profit = 0;
        if(l == 2)
        {
            max_profit = prices[1] - prices[0];
            max_profit = max_profit > 0 ? max_profit : 0;
        }
        else if(l > 2)
        {
            int p1,p2;
            for(int i = 0; i < l - 1; i++)
            {
                p1 = MaxProfit(prices, 0, i);
                p2 = MaxProfit(prices, i+1, l-1);
                if(max_profit < p1 + p2)
                {
                    max_profit = p1 + p2;
                }
            }
            p1 = MaxProfit(prices, 0, l-1);
            max_profit = max_profit > p1 ? max_profit : p1;
        }
        return max_profit;
    }
};
