//https://leetcode.com/problems/permutations/
class Solution {
public:
// void permuteHelp(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, vector<bool>& visit) {
//     if (cur.size() == nums.size()) {
//         res.push_back(cur);
//         return;
//     }
//     for (int i = 0; i < nums.size(); ++i) {
//         if (visit[i]) continue;
//         visit[i] = true;
//         cur.push_back(nums[i]);
//         permuteHelp(nums, res, cur, visit);
//         cur.pop_back();
//         visit[i] = false;
//     }
// }

// vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int>> res;
//     vector<int> cur;
//     vector<bool> visit(nums.size(), false);
//     permuteHelp(nums, res, cur, visit);
//     return res;
// }

void nextPermutation(vector<int>& nums) {
    int sz = nums.size();
    int smaller = -1, greater = -1;
    for (int i = 1; i < sz; i++) {
        if (nums[i-1] < nums[i]) {
            smaller = i-1;
            greater = i;
        }
        if (smaller != -1 && nums[i] < nums[greater] && nums[i] > nums[smaller]) {
            greater = i;
        }
    }
    if (smaller == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    swap(nums[smaller], nums[greater]);
    sort(nums.begin()+smaller+1, nums.end());
}

//time O(n! * nlogn)
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    int n = 1;
    for(int i = 1; i <= nums.size(); ++i) {
        n *= i;
    }
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; ++i) {
        res.push_back(nums);
        nextPermutation(nums);
    }
    return res;
}
};
