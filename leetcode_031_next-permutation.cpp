//https://leetcode.com/problems/next-permutation/
class Solution {
public:
//find the last num nums[smaller] that smaller than the nums behind it.
//then find the smallest num nums[greater] after the nums[smaller] and greater than nums[smaller].
//swap nums[smaller] and nums[greater], resort the nums after nums[smaller]
//time O(nlogn) space O(1)
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
};
