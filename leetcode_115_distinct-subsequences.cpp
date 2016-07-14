//https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
//time O(n*m), space O(n*m)
int numDistinct(string s, string t) {
    int sl = s.length(), tl = t.length();
    if(sl < tl) return 0;
    int dp[tl+1][sl+1] = {0};
    //first row initialized to 1
    for(int i = 0; i <= sl; ++i) dp[0][i] = 1;
    for(int i = 1; i <= tl; ++i){
        for(int j = i; j <= sl; ++j){
            if(s[j-1] == t[i-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }else dp[i][j] = dp[i][j-1];
        }
    }
    return dp[tl][sl];
}

//space O(n)
// int numDistinct(string s, string t) {
//     int sl = s.length(), tl = t.length();
//     if(sl < tl) return 0;
//     vector<int> dp(sl+1, 1);
//     //first row initialized to 1
//     for(int i = 1; i <= tl; ++i){
//         int pre = 0, newpre = 0;
//         for(int j = i; j <= sl; ++j){
//             if(s[j-1] == t[i-1]){
//                 newpre = dp[j-1] + pre;
//             }else newpre = pre;
//             dp[j-1] = pre;
//             pre = newpre;
//         }
//         dp[sl] = pre;
//     }
//     return dp[sl];
// }
};
