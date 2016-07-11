//https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
//time O(n), space O(1)
//https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
// void wiggleSort(vector<int>& nums) {
//     int n = nums.size();
    
//     //find a median
//     nth_element(nums.begin(), nums.begin() + n/2, nums.end());
//     int mid = *(nums.begin() + n/2);
    
//     // Index-rewiring.
//     #define A(i) nums[(1+2*(i)) % (n|1)]

//     // 3-way-partition-to-wiggly in O(n) time with O(1) space.
//     int i = 0, j = 0, k = n - 1;
//     while(j <= k){
//         if(A(j) > mid) swap(A(i++), A(j++));
//         else if(A(j) < mid) swap(A(j), A(k--));
//         else j++;
//     }
// }

//time O(nlogn), space O(n)
void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i = nums.size()-1, j = 0, k = i/2+1; i >= 0; i--)
        nums[i] = sorted[i&1 ? k++ : j++];
}
};
