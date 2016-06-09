//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
class Solution {
public:
//time O(n) space O(1)
TreeNode* sortedArrayToBSTHelp(vector<int>& nums, int s, int e) {
    if(s > e) return NULL;
    int m = (s + e) / 2;
    TreeNode *root = new TreeNode(nums[m]);
    root->left = sortedArrayToBSTHelp(nums, s, m-1);
    root->right= sortedArrayToBSTHelp(nums, m+1, e);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelp(nums, 0, nums.size()-1);
}
};
