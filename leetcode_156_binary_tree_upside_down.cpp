//http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-upside-down.html
/*
Binary Tree Upside Down
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
*/
  
class Solution {
public:
//just change the left child and root's children, right child's children are always empty
TreeNode *upsideDownBinaryTree(TreeNode *root) {
	TreeNode *preleft = NULL, *preright = NULL, *left, *right;
	while(root){
		left = root->left;
		right = root->right;

		root->left = preright;
		root->right = preleft;

		preright = right;
		preleft = root;
		root = left;
	}
	return preleft;
}
};
