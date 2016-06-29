//http://www.cnblogs.com/grandyang/p/5541012.html
//Android Unlock Patterns
//
//Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
//Rules for a valid pattern:
//
//Each pattern must connect at least m keys and at most n keys.
//All the keys must be distinct.
//If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
//The order of keys used matters.
//
//Explanation:
//
//| 1 | 2 | 3 |
//| 4 | 5 | 6 |
//| 7 | 8 | 9 |
//
//Invalid move: 4 - 1 - 3 - 6 
//Line 1 - 3 passes through key 2 which had not been selected in the pattern.
//
//Invalid move: 4 - 1 - 9 - 2
//Line 1 - 9 passes through key 5 which had not been selected in the pattern.
//
//Valid move: 2 - 4 - 1 - 3 - 6
//Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
//
//Valid move: 6 - 5 - 4 - 1 - 9 - 2
//Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
//
//Example:
//Given m = 1, n = 1, return 9.

int dfs(const vector<vector<int>>& jump, vector<bool>& visited, int m, int n, int cnt, int len, int cur){
	if(len >= m) cnt++;
	len++;
	if(len > n) return cnt;
	visited[cur] = true;
	for(int next = 1; next <= 9; ++next){
		if(visited[next]==false && (jump[cur][next]==0 || visited[jump[cur][next]]==true)){
			cnt = dfs(jump, visited, m, n, cnt, len, next);
		}
	}
	visited[cur] = false;
	return cnt;
}

int Q351::numberOfPatterns(int m, int n){
	int res = 0;
	vector<bool> visited(10, false);
	vector<vector<int>> jump(10, vector<int>(10, 0));
	jump[1][3] = jump[3][1] = 2;
	jump[4][6] = jump[6][4] = 5;
	jump[7][9] = jump[9][7] = 8;
	jump[1][7] = jump[7][1] = 4;
	jump[2][8] = jump[8][2] = 5;
	jump[3][9] = jump[9][3] = 6;
	jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;
	res += 4 * dfs(jump, visited, m, n, 0, 1, 1);
	res += 4 * dfs(jump, visited, m, n, 0, 1, 2);
	res += dfs(jump, visited, m, n, 0, 1, 5);
	return res;
}
