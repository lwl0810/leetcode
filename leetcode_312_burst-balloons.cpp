//https://leetcode.com/problems/burst-balloons/

class Solution {
public:
//dp space:O(n^2) time: roughly O(n^3)
int maxCoins(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    vector<vector<int>> dp(sz, vector<int>(sz, 0));
    //compute the max coins can earn in every start to end range
    for(int len = 1; len <= sz; ++len){
        for(int start = 0; start+len <= sz; ++start){
            int end = start+len-1;
            //m is the last ballon to burst
            for(int m = start; m <= end; ++m){
                int coins = 0;
                if(m > start) coins += dp[start][m-1];
                if(m < end) coins += dp[m+1][end];
                int left = 1, right = 1;
                if(start != 0) left = nums[start-1];
                if(end != sz-1) right = nums[end+1];
                coins += left * nums[m] * right;
                dp[start][end] = max(dp[start][end], coins);
            }
        }
    }
    return dp[0][sz-1];
}
};
