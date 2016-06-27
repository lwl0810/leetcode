//https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
//time O(n^2) 
//space can be improved to O(n)(make the value of map be the size of subset and the previous number of key belong to the subset)
//map:key subset's largest number, value subset
// vector<int> largestDivisibleSubset(vector<int>& nums) {
//     unordered_map<int, vector<int>> subsets;
//     sort(nums.begin(), nums.end());
//     unordered_map<int, vector<int>>::iterator it;
//     for(int i = 0; i < nums.size(); ++i){
//         vector<int> cur;
//         for(it = subsets.begin(); it != subsets.end(); ++it){
//             int maxNum = it->first;
//             if(nums[i]%maxNum == 0 && cur.size() < it->second.size()){
//                 cur = it->second;
//             }
//         }
//         cur.push_back(nums[i]);
//         subsets[nums[i]] = cur;
//     }
//     vector<int> res;
//     for(it = subsets.begin(); it != subsets.end(); ++it){
//         if(it->second.size() > res.size()){
//             res = it->second;
//         }
//     }
//     return res;
// }

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int sz = nums.size();
    vector<int> setSize(sz, 0); //setSize[i] is the ith subset size which the subset's largest number is nums[i]
    vector<int> preIdx(sz, -1); //preIdx[i] is the index of number in nums that at nums[i]'s previous position in ith subset.
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i){
        for(int j = 0; j < i; ++j){
            if(nums[i]%nums[j] == 0 && setSize[i] < setSize[j]){
                setSize[i] = setSize[j];
                preIdx[i] = j;
            }
        }
        setSize[i]++;
    }
    //find out the largest subset
    int maxSize = 0, curidx = -1;
    for(int i = 0; i < sz; ++i){
        if(setSize[i] > maxSize){
            maxSize = setSize[i];
            curidx = i;
        }
    }
    //construct the subset
    vector<int> res(maxSize, 0);
    for(int i = maxSize - 1; i >= 0; --i){
        res[i] = nums[curidx];
        curidx = preIdx[curidx];
    }
    return res;
}
};
