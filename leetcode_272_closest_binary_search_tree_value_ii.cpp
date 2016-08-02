//http://www.cnblogs.com/jcliBlogger/p/4771342.html
/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:
Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.
*/

class Solution {
public:
void inorder(TreeNode* root, vector<int>& res, double target, bool reverse){
	if(!root) return;
	inorder(reverse? root->right: root->left, res, target, reverse);
	if((reverse && root->val <= target) || (!reverse && root->val > target)) return;
	res.push_back(root->val);
	inorder(reverse? root->left: root->right, res, target, reverse);
}

vector<int> closestKValues(TreeNode* root, double target, int k){
	vector<int> pre, suc;
	inorder(root, pre, target, false); //node > target and put from greater to smaller
	inorder(root, suc, target, true); //node <= target and put from smaller to greater
	vector<int> res;
	int i = pre.size()-1, j = suc.size()-1;
	while(i >= 0 && j >= 0){
		if(fabs(pre[i] - target) < fabs(suc[j] - target)) res.push_back(pre[i--]);
		else res.push_back(suc[j--]);
		if(--k == 0) break;
	}
	while(k > 0 && i >= 0) res.push_back(pre[i--]);
	while(k > 0 && j >= 0) res.push_back(suc[j--]);
	return res;
}
};
