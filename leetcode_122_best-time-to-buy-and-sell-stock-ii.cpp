https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
//time space O(n), space O(1)
//You may complete as many transactions as you like.
int maxProfit(vector<int>& prices) {
    int maxVal = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if(prices[i] > prices[i-1]) {
            maxVal += prices[i] - prices[i-1];
        }
    }
    return maxVal;
}
};
