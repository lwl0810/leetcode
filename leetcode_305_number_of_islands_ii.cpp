//http://www.cnblogs.com/jcliBlogger/p/4965051.html
/*
Number of Islands II
A 2d grid map of m rows and n columns is initially filled with water. 
We may perform an addLand operation which turns the water at position (row, col) into a land. 
Given a list of positions to operate, count the number of islands after each addLand operation. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example:
Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]
*/


class Solution {
public:
int find(int id, vector<int>& indice) {
	while(id != indice[id]){
		indice[id] = indice[indice[id]];
		id = indice[id];
	}
	return id;
}

//time O(klog(m*n)) space O(m*n)
vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
	vector<int> res;
	vector<int> indice(m*n, -1);
	int direct[] = {0, -1, 0, 1, 0};
	int cnt = 0;
	for(int i = 0; i < positions.size(); ++i) {
		++cnt;
		int x = positions[i].first, y = positions[i].second;
		int idx = x * n + y;
		indice[idx] = idx;
		for(int d = 0; d < 4; ++d) {
			int nx = x + direct[d], ny = y + direct[d+1];
			int nidx = nx * n + ny;
			if(nx >= 0 && ny >= 0 && nx < m && ny < n && indice[nidx] != -1){
				nidx = find(nidx, indice);
				if(idx != nidx) {
					indice[nidx] = idx;
					cnt--;
				}
			}
		}
		res.push_back(cnt);
	}
	return res;
}
};
