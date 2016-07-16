//https://leetcode.com/problems/count-of-range-sum/

class BSTNode{
public:
    int cnt, lcnt;
    long val;
    BSTNode *left, *right;
    BSTNode(long v):val(v),cnt(1),lcnt(0),left(NULL),right(NULL){}
};

class Solution {
public:
//time O(nlogn) if BST is balanced, otherwise worst case O(n^2), space O(n), beats 11%
// void insertBSTNode(BSTNode* cur, BSTNode *node){
//     if(cur->val == node->val) cur->cnt++;
//     else if(cur->val < node->val){
//         if(cur->right) insertBSTNode(cur->right, node);
//         else cur->right = node;
//     }else{
//         cur->lcnt++;
//         if(cur->left) insertBSTNode(cur->left, node);
//         else cur->left = node;
//     }
// }

// int binarySearch(BSTNode* root, long target, bool isLower){
//     BSTNode *cur = root, *pre = NULL;
//     int res = 0;
//     while(cur){
//         pre = cur;
//         if(cur->val == target){
//             res += cur->cnt + cur->lcnt;
//             break;
//         }else if(cur->val < target){
//             res += cur->cnt + cur->lcnt;
//             cur = cur->right;
//         }else{
//             cur = cur->left;
//         }
//     }
//     if(isLower) res -= pre->val == target? pre->cnt: 0; 
//     return res;
// }

// int countRangeSum(vector<int>& nums, int lower, int upper) {
//     int sz = nums.size(), res = 0;
//     if(sz == 0) return 0;
//     long sum = 0;
//     BSTNode *root = NULL, *node = NULL;
//     for(int i = 0; i < sz; ++i){
//         node = new BSTNode(sum);
//         if(root) insertBSTNode(root, node);
//         else root = node;
//         sum += nums[i];
//         res += (binarySearch(root, sum-lower, false) - binarySearch(root, sum-upper, true));
//     }
//     return res;
// }

//time O(nlogn) if consider insert operation of vector as O(1), space O(n), beats 17%
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
