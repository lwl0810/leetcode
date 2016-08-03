//http://blog.csdn.net/u012175043/article/details/50201133
/*
Binary Tree Vertical Order Traversal 
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /   \
       15   7
return its vertical order traversal as:
    [
      [9],
      [3,15],
      [20],
      [7]
    ]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
    [
      [4],
      [9],
      [3,5,2],
      [20],
      [7]
    ]
Hide Company Tags Facebook
Hide Tags Hash Table
Hide Similar Problems (E) Binary Tree Level Order Traversal
*/

class Solution{
public:
//time O(nlogn) space O(n)
vector<vector<int>> verticalOrder(TreeNode* root) {
	map<int, vector<int>> m;
	vector<vector<int>> res;
	queue<pair<int, TreeNode*>> q;
	q.push(make_pair(0, root));
	while(!q.empty()){
		int idx = q.front().first;
		TreeNode *cur = q.front().second;
		m[idx].push_back(cur->val);
		q.pop();
		if(cur->left) q.push(make_pair(idx-1, cur->left));
		if(cur->right)q.push(make_pair(idx+1, cur->right));
	}
	for(map<int,vector<int>>::iterator it = m.begin(); it != m.end(); ++it){
		res.push_back(it->second);
	}
	return res;
}
};
