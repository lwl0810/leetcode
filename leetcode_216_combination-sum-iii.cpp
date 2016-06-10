//https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
void combinationSum(vector<vector<int>>& res, vector<int>& cur, int k, int remain, int pos) {
    if(k == cur.size()) {
        if(remain == 0) res.push_back(cur);
        return;
    }
    for (int i = pos; i <= 9; ++i) {
        if(remain - i < 0) break;
        remain -= i;
        cur.push_back(i);
        combinationSum(res, cur, k, remain, i+1);
        remain += i;
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    combinationSum(res, cur, k, n, 1);
    return res;
}
};
