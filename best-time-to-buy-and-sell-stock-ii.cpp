class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int l = prices.size();
        if(l > 0)
        {
            int max_till_now = prices[0];
            int buy_price = prices[0];
            int i = 1;
            while(i<l)
            {
                if(prices[i] > max_till_now)
                {
                    max_till_now = prices[i];
                }
                else
                {
                    //sell and buy again al lower price
                    total_profit += (max_till_now - buy_price);
                    buy_price = max_till_now = prices[i];
                }
                ++i;
            }
            if(max_till_now - buy_price > 0)
            {
                total_profit += (max_till_now - buy_price);
            }
        }
        return total_profit;
        
    }
};
