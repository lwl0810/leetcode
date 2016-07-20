//https://leetcode.com/problems/dungeon-game/

class Solution {
public:
//time O(m*n), space O(m*n), can be O(min(m,n))
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    //dp[i][j]: the minHp needed start from position (i, j) to pricess 
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = m-1; i >= 0; --i){
        for(int j = n-1; j >=0; --j){
            if(i == m-1 && j == n-1){
                dp[i][j] = max(1, 1-dungeon[i][j]);
            }
            else if(i == m-1){
                dp[i][j] = max(1, dp[i][j+1]-dungeon[i][j]);
            }
            else if(j == n-1){
                dp[i][j] = max(1, dp[i+1][j]-dungeon[i][j]);
            }else{
                int moveRight = max(1, dp[i][j+1]-dungeon[i][j]);
                int moveDown  = max(1, dp[i+1][j]-dungeon[i][j]);
                dp[i][j] = min(moveRight, moveDown);
            }
        }
    }
    return dp[0][0];
}
};
