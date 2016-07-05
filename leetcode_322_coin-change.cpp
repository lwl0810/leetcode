//https://leetcode.com/problems/coin-change/

class Solution {
public:
//time O(n*amount), space O(amount)
int coinChange(vector<int>& coins, int amount) {
    int sz = coins.size();
    sort(coins.begin(), coins.end());
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= amount; ++i){
        for(int c = 0; c < sz; ++c){
            if(coins[c] > i) break;
            if(dp[i-coins[c]] == INT_MAX) continue;
            dp[i] = min(dp[i], dp[i-coins[c]]+1);
        }
    }
    if(dp[amount] == INT_MAX) return -1;
    return dp[amount];
}
};
