//https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
//time O(n*k) space O(n)
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    sort(nums.begin(), nums.end());
    dp[0] = 1;
    for(int i = 1; i <= target; ++i){
        for(int j = 0; j < nums.size(); ++j){
            if(i - nums[j] < 0) break;
            dp[i] += dp[i-nums[j]];
        }
    }
    return dp[target];
}
};
