//https://leetcode.com/problems/count-of-range-sum/

class Solution {
public:
//time O(nlogn) if consider insert operation of vector as O(1), space O(n)
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int sz = nums.size(), cnt = 0;
    //sum: sum of elems from 0 to i
    //sums[j]:sum of elems from 0 to j-1
    //sum - sums[j]: sum of elems from j to i
    vector<long> sums;
    long sum = 0;
    //lower <= sum+nums[i]-ns[x] <= upper (sum+nums[i]-upper <= ns[x] <= sum+nums[i]-lower) 
    for(int i = 0; i < sz; ++i){
        sums.insert(lower_bound(sums.begin(), sums.end(), sum), sum);
        sum += nums[i];
        cnt += distance(lower_bound(sums.begin(), sums.end(), sum-upper), upper_bound(sums.begin(), sums.end(), sum-lower));
    }
    return cnt;
}
};
