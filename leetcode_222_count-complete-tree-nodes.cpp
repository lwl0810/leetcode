//https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
//time O(logn * log(2^(n-1)))

int getHeight(TreeNode* root) {
    if(!root) return 0;
    return 1 + getHeight(root->left);
}
/*
//recursion solution
int countNodesHelp(TreeNode* root, int height) {
    if(!root) return 0;
    int leftHeight = height-1;
    if(leftHeight == 0) return 1;
    int rightHeight = getHeight(root->right);
    
    if(leftHeight == rightHeight) {
        return 1 + (int)(pow(2.0, (double)leftHeight))-1 + countNodesHelp(root->right, rightHeight);
    }
    return 1 + (int)(pow(2.0, (double)rightHeight))-1 + countNodesHelp(root->left, leftHeight);
}

int countNodes(TreeNode* root) {
    int cnt = 0;
    int height = getHeight(root);
    return countNodesHelp(root, height);
}
*/

//iteration solution
int countNodes(TreeNode* root)
{
	if(!root)return 0;
	int depth=getHeight(root);
	int fullLeafNum=pow((double)2, depth-1);
	int leafNum=0, depthTmp=depth, leafNumTemp=fullLeafNum;
	
	while(depthTmp>1){
		leafNumTemp=leafNumTemp>>1;
		int depthRSubTree=getHeight(root->right);
		//leafNum add pow(2,leftDepth-1)，continue on root->right;
		if(depthRSubTree==depthTmp-1){
			leafNum+=leafNumTemp;
			root=root->right;
		}else{
		//continue on root->left;
			root=root->left;
		}
		depthTmp--;
	}
	leafNum+=1;//add the last node outside while
	return leafNum+fullLeafNum-1;
}
};
