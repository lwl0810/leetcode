//https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/

class Solution {
public:
//time O[min(m,n)^2 * max(m,n) * log(max(m,n))], space O(max(m, n))
//assume the number of rows is much larger than the number of columns
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
    for(int l = 0; l < n; ++l){
        vector<int> sums(m, 0);
        for(int r = l; r < n; ++r){
            for(int i = 0; i < m; ++i){
                sums[i] += matrix[i][r]; //accumulate from l to r
            }
            
            set<int> accumulateSet;
            accumulateSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for(int sum: sums){
                curSum += sum; //accumulate from first row to last row
                set<int>::iterator it = accumulateSet.lower_bound(curSum - k);
                if(it != accumulateSet.end()) curMax = max(curMax, curSum - *it);
                accumulateSet.insert(curSum);
            }
            res = max(res, curMax);
        }
    }
    return res;
}
};
