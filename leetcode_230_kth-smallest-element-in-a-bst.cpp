//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
//time O(k), space O(logn)
//recursion solution
int inorder(TreeNode* root, int& k) {
    if(!root) return NULL;
    int res = inorder(root->left, k);
    if(k == 0) return res;
    k--;
    if(k == 0) return root->val;
    return inorder(root->right, k);
}

// int kthSmallest(TreeNode* root, int k) {
//     return inorder(root, k);
// }

//iteration solution
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    while(root || !s.empty()) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        if(!s.empty()) {
            root = s.top();
            s.pop();
            k--;
            if(k == 0) break;
            root = root->right;
        }
    }
    return root->val;
}
};
