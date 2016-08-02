//http://www.cnblogs.com/jcliBlogger/p/4783051.html
/*
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
Note:
n and k are non-negative integers.
*/

class Solution {
public:
//time O(n) space O(n) or O(1)
int numWays(int n, int k) {
	// if(n < 2 || k == 0) return n*k;
	// int same = k, diff1 = k, diff2 = k * (k-1);
	// for(int i = 2; i < n; ++i){
	// 	same = diff2;
	// 	diff2 = (k - 1) * (diff1 + diff2);
	// 	diff1 = same;
	// }
	// return same + diff2;
	
	if(k == 0 || n < 2) return n * k;
	vector<int> dps(n, 0), dpd(n, 0); //dps: i & i-1 are same, dpd: i & i-1 are different
	dps[0] = k; dps[1] = k; 
	dpd[0] = k; dpd[1] = (k - 1) * k;
	for(int i = 2; i < n; i++){
		dps[i] = dpd[i-1];
		dpd[i] = (k-1) * (dpd[i-1] + dps[i-1]);
	}
	return dps[n-1] + dpd[n-1];
}
};
