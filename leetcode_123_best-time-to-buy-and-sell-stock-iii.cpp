//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
//time O(n), space O(n).
//caculate both left to right and right to left maximum profit.
//you may complete at most two transactions means only one transaction is also possible
//in this caculation way, it cannot be possible that one day price be both the sell and buy day, 
//if it is possible, the two transactions can be merged to one
int maxProfit(vector<int>& prices) {
    int sz = prices.size();
    if(sz == 0) return 0;
    vector<int> l2rProfit(sz, 0), r2lProfit(sz, 0);
    
    int lowestPrice = prices[0];
    for (int i = 1; i < sz; ++i) {
        l2rProfit[i] = max(l2rProfit[i-1], prices[i]-lowestPrice);
        lowestPrice = min(lowestPrice, prices[i]);
    }
    
    int highestPrice = prices[sz-1];
    for (int i = sz-2; i >= 0; --i) {
        r2lProfit[i] = max(r2lProfit[i+1], highestPrice-prices[i]);
        highestPrice = max(highestPrice, prices[i]);
    }
    
    int maxVal = 0;
    for (int i = 0; i < sz; ++i) {
        maxVal = max(maxVal, l2rProfit[i] + r2lProfit[i]);
    }
    return maxVal;
}
};
