//http://www.cnblogs.com/jcliBlogger/p/4763200.html
/*
Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

class Solution{
public:
//time O(logn) space O(1)
int closestValue(TreeNode* root, double target) {
	if(!root) return INT_MAX;
	double minGap = fabs(root->val - target);
	int closest = root->val;
	TreeNode *t = root;
	while(t){
		if(t->left && fabs(t->left->val - target) < minGap){
			minGap = fabs(t->left->val - target);
			closest = t->left->val;
		}
		if(t->right && fabs(t->right->val - target) < minGap){
			minGap = fabs(t->right->val - target);
			closest = t->right->val;
		}
		if(t->val == target) return t->val;
		else if(t->val > target) t = t->left;
		else t = t->right;
	}
	return closest;
}
};
