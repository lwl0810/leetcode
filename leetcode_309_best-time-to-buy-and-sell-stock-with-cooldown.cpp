//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
//time O(n), space O(n)
int maxProfit(vector<int>& prices) {
    int sz = prices.size(), maxProfit = 0;
    if(sz <= 1) return 0;
    //the maximum profit from 0 - i that buy or sell on ith day.
    vector<int> sell(sz, 0), buy(sz, 0);
    buy[0] = -prices[0];
    for ( int i = 1; i < sz; ++i) {
        if(i == 1) buy[i] = -prices[i];
        else buy[i] = max(buy[i-1]+prices[i-1]-prices[i], sell[i-2]-prices[i]);
        sell[i]= max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
        maxProfit = max(maxProfit, sell[i]);
    }
    return maxProfit;
}
};
