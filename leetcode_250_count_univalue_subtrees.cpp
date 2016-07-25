//http://www.voidcn.com/blog/pointbreak1/article/p-4357160.html
/*
Count Univalue Subtrees
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
*/

class Solution{
public:
//iteration solution
int countUnivalSubtrees(TreeNode* root){
	unordered_map<TreeNode*, int> isUnival;
	stack<TreeNode*> s;
	int cnt = 0;
	while(root || !s.empty()){
		while(root){
			s.push(root);
			isUnival[root] = 0;  //0:visited, -1 or 1:visited
			root = root->left;
		}
		if(!s.empty()){
			root = s.top();
			if(isUnival[root] == 0){
				isUnival[root] = -1;
				root = root->right;
			}else{
				s.pop();
				if(	(!root->left || isUnival[root->left] == 1 && root->left->val == root->val) && 
					(!root->right || isUnival[root->right] == 1 && root->right->val == root->val)){
					isUnival[root] = 1;
					++cnt;
				}else{
					isUnival[root] = -1;
				}
				root = NULL;
			}
		}
	}
	return cnt;
}

//recursion solution
bool countHelper(TreeNode* root, int &cnt){
	if(!root) return true;
	if(countHelper(root->left) && countHelper(root->right)){
		if( (!root->left  || root->val == root->left->val) && 
			(!root->right || root->val == root->right->val)){
			++cnt;
			return true;
		}
	}
	return false;
}

int countUnivalSubtrees(TreeNode* root){
	int cnt = 0;
	countHelper(root, cnt);
	return cnt;
}
};
