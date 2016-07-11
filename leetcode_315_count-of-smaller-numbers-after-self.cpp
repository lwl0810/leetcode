//https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
//time O(nlogn), space O(n)
//binary search and insert sort
int binarySearch(vector<int>& sorts, int target){
    int start = 0, end = sorts.size()-1, mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(sorts[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

vector<int> countSmaller(vector<int>& nums) {
    int sz = nums.size();
    vector<int> sorts, res(sz, 0);
    if(sz == 0) return res;
    sorts.push_back(nums[sz-1]);
    for(int i = sz-2; i >= 0; --i){
        int idx = binarySearch(sorts, nums[i]);
        res[i] = idx;
        sorts.insert(sorts.begin() + idx, nums[i]);
    }
    return res;
}
};
