//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

struct Item{
    int val;
    int row;
    int col;
    Item(int v, int r, int c):val(v), row(r), col(c){}
};

class mycomp{
public:
	mycomp(){}
	bool operator()(Item *a, Item *b){
		return a->val > b->val;
	}
};

class Solution {
public:
//time O(m*n*logm) space O(m)
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int row = matrix.size(), col = matrix[0].size();
    int cnt = 0;
    priority_queue<Item*, vector<Item*>, mycomp> pq;
    for(int i = 0; i < row; ++i){
        pq.push(new Item(matrix[i][0], i, 0));
    }
    
    Item *it;
    while(cnt < k){
        ++cnt;
        it = pq.top();
        pq.pop();
        if(it->col+1 == col) continue;
        pq.push(new Item(matrix[it->row][it->col+1], it->row, it->col+1));
    }
    return it->val;
}
};
