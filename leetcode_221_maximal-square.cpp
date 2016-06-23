//https://leetcode.com/problems/maximal-square/
class Solution {
public:
//time O(n^2), space O(n^2) / O(n)
//dynamic programming: the maximum edge at position i,j: dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    int maxVal = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == '1'){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }else dp[i][j] = 0;
            maxVal = max(maxVal, dp[i][j]*dp[i][j]);
        }
    }
    return maxVal;
}
};
