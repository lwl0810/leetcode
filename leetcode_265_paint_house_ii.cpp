//https://segmentfault.com/a/1190000003903965
/*
Paint House II
There are a row of n houses, each house can be painted with one of the k colors. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; 
costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses
Note:
All costs are positive integers.
Follow up: 
Could you solve it in O(nk) runtime?
*/

class Solution{
public:
//time O(nk), space O(1)
int minCostII(vector<vector<int>> costs){
	int houses = costs.size();
	if(houses == 0) return 0;
	int colors = costs[0].size();
	//previous minimum cost and previous second minimum cost, color of previous minimum cost
	int pre1stMin = 0, pre2ndMin = 0, pre1stColor = -1;
	for(int i = 0; i < houses; ++i){
		int cur1stMin = INT_MAX, cur2ndMin = INT_MAX, cur1stColor = -1;
		for(int j = 0; j < colors; ++j){
			int tmpCost = 0;
			if(j != pre1stColor) tmpCost = pre1stColor + costs[i][j];
			else tmpCost = pre2ndColor + costs[i][j];
			if(tmpCost <= cur1stMin){
				cur2ndMin = cur1stMin;
				cur1stMin = tmpCost; 
				cur1stColor = j;
			}else if(tmpCost < cur2ndMin){
				cur2ndMin = tmpCost;
			}
		}
		pre1stMin = cur1stMin; 
		pre2ndMin = cur2ndMin; 
		pre1stColor = cur1stColor;
	}
	return cur1stMin;
}
};
