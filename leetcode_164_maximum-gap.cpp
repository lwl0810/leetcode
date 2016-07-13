//https://leetcode.com/problems/maximum-gap/

class Solution {
public:
//bucket solution
int maximumGap(vector<int>& nums) {
    int sz = nums.size(), minVal = INT_MAX, maxVal = INT_MIN, res = 0;
    if(sz < 2) return 0;
    for(int i = 0; i < sz; ++i){
        minVal = min(minVal, nums[i]);
        maxVal = max(maxVal, nums[i]);
    }
    //consider the test case that all the nums are the same
    if(minVal == maxVal) return abs(nums[0] - nums[1]);
    int bucketSize = ceil((double)(maxVal - minVal)/(sz-1));
    int bucketNum = (maxVal - minVal)/bucketSize+1;
    vector<pair<int,int>> buckets(bucketNum, make_pair(INT_MAX, INT_MIN));
    for(int i = 0; i < sz; ++i){
        int bucketIdx = (nums[i] - minVal) / bucketSize;
        buckets[bucketIdx].first = min(nums[i], buckets[bucketIdx].first);
        buckets[bucketIdx].second= max(nums[i], buckets[bucketIdx].second);
    }
    
    int preMax = INT_MAX, curMin = INT_MIN;
    for(int i = 0; i < bucketNum; ++i){
        if(buckets[i].first != INT_MAX) curMin = buckets[i].first;
        if(preMax != INT_MIN && curMin != INT_MAX) res = max(res, curMin - preMax);
        if(buckets[i].second != INT_MIN) preMax = buckets[i].second;
    }
    return res;
}
};
