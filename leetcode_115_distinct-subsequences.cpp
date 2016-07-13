//https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
//time O(n^2), space O(n)
int numDistinct(string s, string t) {
    int sl = s.length(), tl = t.length();
    if(sl < tl) return 0;
    vector<vector<int>> dp(tl+1, vector<int>(sl+1, 0));
    //first row initialized to 1
    for(int i = 0; i <= sl; ++i) dp[0][i] = 1;
    for(int i = 1; i <= tl; ++i){
        for(int j = 1; j <= sl; ++j){
            if(s[j-1] == t[i-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }else dp[i][j] = dp[i][j-1];
        }
    }
    return dp[tl][sl];
}
};
