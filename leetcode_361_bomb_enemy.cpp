//http://www.cnblogs.com/grandyang/p/5599289.html

//Bomb Enemy
//Given a 2D grid, each cell is either a wall 'Y', an enemy 'X' or empty '0' (the number zero), 
//return the maximum enemies you can kill using one bomb.
//The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
//Note that you can only put the bomb at an empty cell.
//
//Example:
//For the given grid
//0 X 0 0
//X 0 Y X
//0 X 0 0
//return 3. (Placing a bomb at (1,1) kills 3 enemies)

//time O(m*n) space can be O(1)
int maxKilledEnemies(vector<vector<char>>& grid){
	int m = grid.size();
	if(m == 0) return 0;
	int n = grid[0].size();
	int kills = 0;
	vector<vector<int>> killgrid(m, vector<int>(n, 0));
	for(int i = 0; i < m; ++i){
		kills = 0;
		for(int j = 0; j < n; ++j){
			if(grid[i][j] == '0') killgrid[i][j] += kills;
			if(grid[i][j] == 'X') kills++;
			if(grid[i][j] == 'Y') kills = 0;
		}
		kills = 0;
		for(int j = n-1; j >= 0; --j){
			if(grid[i][j] == '0') killgrid[i][j] += kills;
			if(grid[i][j] == 'X') kills++;
			if(grid[i][j] == 'Y') kills = 0;
		}
	}
	for(int j = 0; j < n; ++j){
		kills = 0;
		for(int i = 0; i < m; ++i){
			if(grid[i][j] == '0') killgrid[i][j] += kills;
			if(grid[i][j] == 'X') kills++;
			if(grid[i][j] == 'Y') kills = 0;
		}
		kills = 0;
		for(int i = m-1; i >= 0; --i){
			if(grid[i][j] == '0') killgrid[i][j] += kills;
			if(grid[i][j] == 'X') kills++;
			if(grid[i][j] == 'Y') kills = 0;
		}
	}

	kills = 0;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			kills = max(kills, killgrid[i][j]);
		}
	}
	return kills;
}
