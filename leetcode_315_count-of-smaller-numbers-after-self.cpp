//https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
//time O(nlogn), space O(n)
//binary search and insert sort
/*
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
*/

//Binary Index Tree Solution
vector<int> countSmaller(vector<int>& nums) {
    int sz = nums.size();
    //key: nums[i], value: rank
    map<int, int> num2Rank;
    for(int i = 0; i < sz; ++i){
        num2Rank[nums[i]] = 0;
    }
    int idx = 0;
    for(map<int, int>::iterator it = num2Rank.begin(); it != num2Rank.end(); ++it){
        it->second = ++idx;
    }
    
    vector<int> res(sz, 0);
    vector<int> binaryIndexTree(idx+1, 0); //not sz+1, nums may contain duplicates
    for(int i = sz-1; i >= 0; --i){
        int rank = num2Rank[nums[i]];
        // update BIT
        for(int idx = rank; idx <= sz; idx += idx&(-idx))
            binaryIndexTree[idx] += 1;
        
        // read BIT
        int cnt = 0;
        for(int idx = rank-1; idx > 0; idx -= idx&(-idx))
            cnt += binaryIndexTree[idx];
            
        res[i] = cnt;
    }
    return res;
}
};
