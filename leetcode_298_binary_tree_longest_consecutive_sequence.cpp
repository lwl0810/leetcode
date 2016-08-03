//http://www.voidcn.com/blog/pointbreak1/article/p-4839310.html
/*
Binary Tree Longest Consecutive Sequence
Given a binary tree, find the length of the longest consecutive sequence path.
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not 3-2-1, so return 2. 
*/

class Solution{
public:
//consecutive sequence is in ascending order
void top2BottomRecursion(TreeNode* root, int curLen, int& maxLen){
	if(!root){
		maxLen = max(maxLen, curLen);
		return;
	}
	++curLen;
	if(root->left){
		if(root->left->val == root->val+1) top2BottomRecursion(root->left, curLen, maxLen);
		else{
			maxLen = max(maxLen, curLen);
			top2BottomRecursion(root->left, 0, maxLen);
		}
	}
	if(root->right){
		if(root->right->val == root->val+1) top2BottomRecursion(root->right, curLen, maxLen);
		else{
			maxLen = max(maxLen, curLen);
			top2BottomRecursion(root->right, 0, maxLen);
		}
	}
}

int longestConsecutive(TreeNode* root) {
	int maxLen = 0;
	top2BottomRecursion(root, 0, maxLen);
	return maxLen;
}
};
