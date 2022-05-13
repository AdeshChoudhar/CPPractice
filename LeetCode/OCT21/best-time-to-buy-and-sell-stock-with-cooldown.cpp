//
// Created by adeshchoudhar on 15/10/21.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int cool_down = 0;
        int sell = 0;
        int wait = -prices[0];

        int previous_sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            previous_sell = sell;
            sell = wait + prices[i];
            wait = max(wait, cool_down - prices[i]);
            cool_down = max(cool_down, previous_sell);
        }

        return max(sell, cool_down);
    }
};
