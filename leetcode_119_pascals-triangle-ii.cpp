//https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
//time O(n*(n+1)/2), space O(n)
vector<int> getRow(int rowIndex) {
    vector<int> res(1,1);
    if(rowIndex == 0) return res;
    for(int i = 1; i <= rowIndex; ++i){
        int tmp = 1, sum = 0;
        for(int j = 1; j < i; ++j){
            sum = tmp + res[j];
            tmp = res[j];
            res[j] = sum;
        }
        res.push_back(1);
    }
    return res;
}
};
