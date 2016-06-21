//https://leetcode.com/problems/house-robber-iii/
class Solution {
public:
int rob(TreeNode* root, bool isRob) {
    int res = 0;
    if(!root) return res;
    if(isRob) {
        if(dp1.find(root) == dp1.end()) {
            dp1[root] = rob(root->left, false) + rob(root->right, false) + root->val;
        }
        res = dp1[root];
    }else {
        if(dp0.find(root) == dp0.end()) {
            dp0[root] = max(max((rob(root->left, true)+rob(root->right, true)), (rob(root->left, true)+rob(root->right, false))),
                            max((rob(root->left, false)+rob(root->right, true)), (rob(root->left, false)+rob(root->right, false))));
        }
        res = dp0[root];
    }
    return res;
}

int rob(TreeNode* root) {
    return max(rob(root, true), rob(root, false));
}

private:
unordered_map<TreeNode*, int> dp0;
unordered_map<TreeNode*, int> dp1;
};
