//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
//time space O(n), space O(1)
//you were only permitted to complete at most one transaction 
int maxProfit(vector<int>& prices) {
    int maxVal = 0, lowestPrice = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
        maxVal = max(maxVal, prices[i]-lowestPrice);
        lowestPrice = min(lowestPrice, prices[i]);
    }
    return maxVal;
}
};
