https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
int rob(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    if(sz == 1) return nums[0];
    if(sz == 2) return max(nums[0], nums[1]);
    vector<int> dp(sz, 0);
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for(int i = 3; i < sz; ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < sz-1; ++i) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    
    return max(dp[sz-2], dp[sz-1]);
}
};
