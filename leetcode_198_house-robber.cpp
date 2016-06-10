//https://leetcode.com/problems/house-robber/
class Solution {
public:
//time O(n), space O(1)
int rob(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0) return 0;
    int h_2 = nums[0], h_1 = max(nums[0], nums[1]), h_0 = 0;
    if(sz == 1) return h_2;
    if(sz == 2) return h_1;
    for(int i = 2; i < sz; ++i) {
        h_0 = max(h_1, h_2 + nums[i]);
        h_2 = h_1;
        h_1 = h_0;
    }
    return h_0;
}
};
