//http://blog.csdn.net/u012175043/article/details/50336803
/*
Shortest Distance from All Buildings
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, 
as the total travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. 
If it is not possible to build such house according to the above rules, return -1.
*/

class Solution{
public:
//time O(k*m*n) space O(m*n)
int shortestDistance(vector<vector<int>>& grid){
	int m = grid.size();
	if(m == 0) return -1;
	int n = grid[0].size();
	//total distance from the empty land to every building
	vector<vector<int>> totalDist(m, vector<int>(n, 0));
	int direction[] = {0, -1, 0, 1, 0};
	//the number of buidlings current visited, can be used to mark visited empty land in every round
	int reachedBuilding = 0;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(grid[i][j] != 1) continue; 
			//caculate the distance from each building to every empty land, add the distance to totalDist of every empty land
			queue<pair<int,int>> q;
			q.push(make_pair(i, j));
			int distance = 0;
			while(!q.empty()){
				++distance;
				int sz = q.size();
				while(sz--){
					int r = q.front().first, c = q.front().second;
					q.pop();
					for(int d = 0; d < 4; ++d){
						int newr = r + direction[d], newc = c + direction[d+1];
						if(newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] == reachedBuilding){
							q.push(make_pair(newr, newc));
							--grid[newr][newc];
							totalDist[newr][newc] += distance;
						}
					}
				}
			}
			--reachedBuilding;
		}
	}
	int minDist = INT_MAX;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(grid[i][j] == reachedBuilding && totalDist[i][j] != 0){
				minDist = min(minDist, totalDist[i][j]);
			}
		}
	}
	return minDist == INT_MAX? -1: minDist;
}
};
