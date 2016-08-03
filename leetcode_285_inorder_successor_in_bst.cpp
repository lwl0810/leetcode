//http://www.cnblogs.com/jcliBlogger/p/4829200.html
/*
Inorder Successor in BST
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.
*/

class Solution {
public:
//time O(logn) space O(1)
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	if(p->right){
		TreeNode *t = p->right;
		while(t->left) t = t->left;
		return t;
	}
	
	TreeNode *t = root, *suc = NULL;
	while(1){
		if(t->val > p->val){
			suc = t;
			t = t->left;
		}else if(t->val < p->val){
			t = t->right;
		}else break;
	}
	return suc;
}
};
