//https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        v = nums;
        int tmp = 0;
        for(int i = 0; i < v.size(); ++i){
            tmp += v[i];
            v[i] = tmp;
        }
    }

    int sumRange(int i, int j) {
        return v[j] - (i == 0? 0: v[i-1]);
    }
    
private:
    vector<int> v;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
