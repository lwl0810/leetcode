//https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
//time O(n), space O(1), greedy: only care about the increasing and decreasing sequence
int wiggleMaxLength(vector<int>& nums) {
    int sz = nums.size(), i = 0, j = 0;
    if(sz == 0) return 0;
    int res = 1;
    while(i < sz-1){
        j = i+1;
        //increasing sequence
        while(j < sz && nums[j-1] <= nums[j]) j++;
        if(j-1 != i && nums[i] < nums[j-1]) res++;
        i = j-1;
        j = i+1;
        //decreasing sequence
        while(j < sz && nums[j-1] >= nums[j]) j++;
        if(j-1 != i && nums[i] > nums[j-1]) res++;
        i = j-1;
    }
    return res;
}

//dynamic programming: time O(n^2), space O(n)
// int wiggleMaxLength(vector<int>& nums) {
//     int sz = nums.size(), res = 0;
//     if(sz == 0) return 0;
//     vector<int> pos(sz, -1), neg(sz, -1);
//     for(int i = 0; i < sz; ++i){
//         for(int j = i-1; j >= 0; --j){
//             if(nums[j] < nums[i]) pos[i] = max(pos[i], neg[j]+1);
//             if(nums[j] > nums[i]) neg[i] = max(neg[i], pos[j]+1); 
//         }
//         if(pos[i] == -1) pos[i] = 1;
//         if(neg[i] == -1) neg[i] = 1;
//         res = max(res, pos[i]);
//         res = max(res, neg[i]);
//     }
//     return res;
// }
};
