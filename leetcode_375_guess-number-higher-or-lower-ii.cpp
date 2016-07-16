//https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
//Minimax theory has been extended to decisions where there is no other player, but where the consequences of decisions depend on unknown facts. 
//For example, deciding to prospect for minerals entails a cost which will be wasted if the minerals are not present, but will bring major rewards if they are. 
//One approach is to treat this as a game against nature (see move by nature), and using a similar mindset as Murphy's law or resistentialism, take an approach which minimizes the maximum expected loss, using the same techniques as in the two-person zero-sum games.
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; ++i) dp[i][i] = 0;
    for(int len = 2; len <= n; ++len){
        for(int i = 0; i+len-1 < n; ++i){
            int j = i+len-1;
            for(int k = i; k <= j; ++k){
                if(k == i) 
                    dp[i][j] = min(dp[i][j], dp[i+1][j]+k+1); //k is the index, k+1 is the cost
                else if(k == j) 
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+k+1);
                else 
                    dp[i][j] = min(dp[i][j], max(dp[i][k-1], dp[k+1][j]) +k+1);
            }
        }
    }
    return dp[0][n-1];
}
};
