//https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
//time: O(n^2), space O(n)
int minCut(string s) {
    // int len = s.length();
    // //dp[i]: the minimun cut of s.substr(0, i)
    // int dp[len+1] = {0};
    // for(int i = 0; i <= len; ++i) dp[i] = i-1;
    // for(int i = 1; i <= len; ++i){
    //     int l = i, r = i;
    //     while(l >= 1 && s[l-1] == s[i-1]){
    //         dp[i] = min(dp[i], dp[l-1]+1);
    //         l--;
    //     }
    //     while(r <= len && s[i-1] == s[r-1]){
    //         dp[r] = min(dp[r], dp[i-1]+1);
    //         r++;
    //     }
    //     while(l >= 1 && r <= len && s[l-1] == s[r-1]){
    //         dp[r] = min(dp[r], dp[l-1]+1);
    //         l--; r++;
    //     }
    // }
    // return dp[len];
    
    int len = s.length();
	if(len <= 1)return 0;
	//dp[i]: the minimun cut of s.substr(0, i)
	vector<int> dp(len+1, 0);
	for(int i = 0; i <= len; i++) dp[i] = i-1;
	for(int i = 1; i < len; i++){
		//odd length
		for(int j = 0; i-j >= 0 && i+j < len && s[i-j] == s[i+j]; j++)
			dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);
		//even length
		for(int j = 0; i-j-1 >= 0 && i+j < len && s[i-j-1] == s[i+j]; j++)
			dp[i+j+1] = min(dp[i+j+1], dp[i-j-1]+1);
	}
	return dp[len];
}
};
