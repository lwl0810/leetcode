//http://www.cnblogs.com/jcliBlogger/p/4901473.html
/*
A group of two or more people wants to meet and minimize the total travel distance. 
You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Hint:
Try to solve it in one dimension first. How can this solution apply to the two dimension case?
*/
//Since the distance is computed using the Manhattan Distance, 
//we can decompose this 2-d problem into two 1-d problems and combine (add) their solutions.
class Solution{
public:
//time O(m*n) space O(m*n)
int minTotalDistance(vector<vector<int>>& grid){
	int m = grid.size();
	if(m == 0) return 0;
	int n = grid[0].size();
	
	vector<int> rows, cols;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(grid[i][j] == 1){
				rows.push_back(i);
				cols.push_back(j);
			}
		}
	}
	sort(cols.begin(), cols.end());
	int rooms = rows.size();
	//median point
	int r = rows[rooms/2];
	int c = cols[rooms/2];
	int distance = 0;
	for(int i = 0; i < rooms; ++i){
		distance += abs(rows[i] - r);
		distance += abs(cols[i] - c);
	}
	return distance;
}


//if the meeting point must be in someone's home
//https://discuss.leetcode.com/topic/27722/o-mn-java-2ms
//https://discuss.leetcode.com/topic/51109/8ms-c-dp-solution-with-o-mn-time-o-m-n-space
int minTotalDistance(vector<vector<int>>& grid){
	int m = grid.size();
	if(m == 0) return 0;
	int n = grid[0].size();
	int rdistance = 0, cdistance = 0;
	int rowSum[m] = {0}, colSum[n] = {0};
	for(int i = 0; i < m; ++i){
		if(rowSum[i] != 0) rowSum = rowSum[i-1];
		for(int j = 0; j < n; ++j){
			rowSum[i] += grid[i][j];
			colSum[j] += (i == 0? rowSum[i]: rowSum[i]-rowSum[i-1]);
			rdistance += grid[i][j] * j;
			cdistance += grid[i][j] * i;
		}
	}
	
	int reduced = 0; //the distance reduced of each move, when reduced >= 0, no need to continue 
	int i = 0, j = 0; //the meeting point, when for loop finished, i and j is the best meeting point;
	for(i = 0; i < m-1; ++i) {
		reduced = rowSum[i] - (rowSum[m-1] - rowSum[i]);
		if(reduced >= 0) break;
		rdistance += reduced;
	}
	for(j = 0; j < n-1; ++j) {
		reduced = colSum[j] - (colSum[n-1] - colSum[j]);
		if(reduced >= 0) break;
		cdistance += reduced;
	}
	return rdistance + cdistance;
}
};


