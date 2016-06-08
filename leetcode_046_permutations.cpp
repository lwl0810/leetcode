//https://leetcode.com/problems/permutations/
class Solution {
public:
//time O(n!) space O(n)
void permuteHelp(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, vector<bool>& visit) {
    if (cur.size() == nums.size()) {
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        cur.push_back(nums[i]);
        permuteHelp(nums, res, cur, visit);
        cur.pop_back();
        visit[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> visit(nums.size(), false);
    permuteHelp(nums, res, cur, visit);
    return res;
}
};
