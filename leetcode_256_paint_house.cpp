//http://www.cnblogs.com/jcliBlogger/p/4729957.html
/*
Paint House
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color red;
costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
Note:
All costs are positive integers.
*/

class Solution{
public:
//dynamic programming, time O(n), space O(1)
int minCost(vector<vector<int>>& costs){
	int sz = costs.size();
	if(sz == 0) return 0;
	int pr = costs[0][0], pb = costs[0][1], pg = costs[0][2];
	int cr = 0, cb = 0, cg = 0;
	for(int i = 1; i < sz; ++i){
		cr = costs[i][0] + min(pb, pg);
		cb = costs[i][1] + min(pr, pg);
		cg = costs[i][2] + min(pr, pb);
		pr = cr;
		pb = cb;
		pg = cg;
	}
	return min(cr, min(cb, cg));
}
};
