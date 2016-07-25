//https://segmentfault.com/a/1190000003874375
/*
Verify Preorder Sequence in Binary Search Tree
Given an array of numbers, verify whether it is the 
correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Follow up:
Could you do it using only constant space complexity?
*/

calss Solution{
public:
//time O(n), space O(n)
bool verifyPreorder(vector<int>& preorder){
	stack<int> s;
	int lower = INT_MIN;
	for(int i = 0; i <  preorder.size(); ++i){
		if(preorder[i] < lower) return false;
		while(!s.empty() && s.top() < preorder[i]){
			lower = s.top();
			s.pop();
		}
		s.push(preorder[i]);
	}
	return true;
}

//follow up, space O(1), reuse the input vector as stack, stacktop is the stack top indicator.
bool verifyPreorder(vector<int>& preorder){
	int stacktop = -1, lower = INT_MIN;
	for(int i = 0; i < preorder.size(); ++i){
		if(preorder[i] < lower) return false;
		while(stacktop != -1 && preorder[stacktop] < preorder[i]){
			lower = s[stacktop--];
		}
		s[++stacktop] = preorder[i];
	}
	return true;
}
};
