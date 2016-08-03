//http://www.cnblogs.com/jcliBlogger/p/4836567.html
/*
Walls and Gates
You are given a m x n 2D grid initialized with these three possible values.
-1  - A wall or an obstacle.
0   - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

//start from every gates conduct bfs traverse
class Solution{
public:
//time O(k*m*n) space O(m*n)
void bfs(vector<vector<int>>& rooms, int i, int j){
	int m = rooms.size(), n = rooms[0].size();
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	int direct[] = {0, -1, 0, 1, 0};
	int distance = 0;
	while(!q.empty()){
		++distance;
		int sz = q.size();
		while(sz--){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int d = 0; d < 4; ++d){
				int xx = x + direct[d];
				int yy = y + direct[d+1];
				if(xx >= 0 && yy >= 0 && xx < m && yy < n && rooms[xx][yy] > distance){
					rooms[xx][yy] = distance;
					q.push(make_pair(xx, yy));
				}
			}
		}
	}
}

void wallsAndGates(vector<vector<int>>& rooms){
	int m = rooms.size();
	if(m == 0) return;
	int n = rooms[0].size();
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(rooms[i][j] == 0){
				bfs(rooms, i, j);
			}
		}
	}
}
};
