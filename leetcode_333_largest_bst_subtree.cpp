//http://codingmelon.com/2016/02/13/largest-bst-subtree-leetcode-333/
/*
Largest BST Subtree
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
where largest means subtree with largest number of nodes in it.
Note:
A subtree must include all of its descendants.
Here’s an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7

The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree’s size, which is 3.
*/

class Solution{
public:
bool validateBST(TreeNode* root, int& minVal, int& maxVal, int& maxSz){
    if(!root) return 0;
    int lmin = INT_MAX, lmax = INT_MIN, rmin = INT_MAX, rmax = INT_MIN, lsz = 0, rsz = 0;
    bool left = validateBST(root->left, lmin, lmax, lsz);
    bool right = validateBST(root->right, rmin, rmax, rsz);
    if(left == false || right == false || root->val <= lmax || root->val >= rmin){
        maxSz = max(lsz, rsz);
        return false;
    }
    maxSz = lsz + rsz + 1;
    //left or right subtree may be null
	maxVal = max(rmax, t->val); 
	minVal = min(lmin, t->val);
	return true;
}

int largestBSTSubtree(TreeNode* root){
    int maxSz = 0, minVal = INT_MAX, maxVal = INT_MIN;
    validateBST(root, minVal, maxVal, maxSz);
    return maxSz;
}
};
