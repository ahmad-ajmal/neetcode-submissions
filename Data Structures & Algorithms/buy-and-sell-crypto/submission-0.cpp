class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int window_start = 0;
        int window_end = 0;
        
        int max_profit = 0;

        int starting_price = prices[0];

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - starting_price > 0)
            {
                if(max_profit < prices[i] - starting_price)
                {
                    max_profit = prices[i] - starting_price;
                }
                continue;
            }

            starting_price = prices[i];
        }

        return max_profit;
    }
};
