//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
//time O(n*k) space O(n) or O(n*k)
int maxProfit(int k, vector<int>& prices) {
    int sz = prices.size();
    if (k >= sz/2) {
        int maxProfit = 0;
        for (int i = 1; i < sz; ++i) {
            if (prices[i] > prices[i-1])
                maxProfit += prices[i] - prices[i-1];
        }
        return maxProfit;
    }
    
    //dp[i][j] represents the max profit up until prices[j] using at most i transactions. 
    vector<vector<int>> dp(k+1, vector<int>(sz, 0));
    for (int i = 1; i <= k; ++i) {
        //localMax: the current maximum profit that not have done the ith transaction, but have already buy the ith without sell it
        int localMax = dp[i-1][0] - prices[0];
        for (int j = 1; j < sz; ++j) {
            dp[i][j] = max(dp[i][j-1], localMax + prices[j]);
            localMax = max(localMax, dp[i-1][j] - prices[j]);
        }
    }
    return dp[k][sz-1];
    
    // vector<int> dp(sz,0);
    // for(int i=1; i<=k; i++){
    //     int localMax=dp[0]-prices[0];
    //     for(int j=1; j<sz; j++){
    //         int newdp=max(dp[j-1], prices[j]+localMax);
    //         localMax=max(localMax, dp[j]-prices[j]);
    //         dp[j]=newdp;
    //     }
    // }
    // return dp[sz-1];
}
};
