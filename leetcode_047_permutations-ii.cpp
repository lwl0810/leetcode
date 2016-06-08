//https://leetcode.com/problems/permutations-ii/
class Solution {
public:
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

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    int n = 1, duplicates = 1;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i) {
        int cur = nums[i];
        int cnt = 1;
        while(i+1 < nums.size() && nums[i+1] == nums[i]) {
            cnt++;
            i++;
            duplicates *= cnt;
        }
    }
    for(int i = 1; i <= nums.size(); ++i) {
        n *= i;
    }
    n /= duplicates;
    for(int i = 0; i < n; ++i) {
        res.push_back(nums);
        nextPermutation(nums);
    }
    return res;
}
};
