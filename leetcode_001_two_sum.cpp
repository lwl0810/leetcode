//https://leetcode.com/problems/two-sum/

class Solution {
public:
//mantain a map to store key:the desired number, value:the index of number equals to target minus desired number
//time: O(n), space O(n), one pass
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> um;
    for(int i = 0; i < nums.size(); ++i) {
        if(um.find(nums[i]) != um.end()) {
            res.push_back(um[nums[i]]);
            res.push_back(i);
            break;
        }
        um[target - nums[i]] = i;
    }
    return res;
}

//time: O(n^2), space O(1)
vector<int> twoSum1(vector<int>& nums, int target) {
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i + 1; j < nums.size(); ++j) {
            if(nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
    }
    return res;
}
};
