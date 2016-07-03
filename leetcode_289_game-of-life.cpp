//https://leetcode.com/problems/game-of-life/

class Solution {
public:
void gameOfLife(vector<vector<int>>& board) {
    if(board.empty()) return;
    int m = board.size(), n = board[0].size();
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int live = 0;
            if(i-1 >= 0 && board[i-1][j] >0) live++;
            if(j-1 >= 0 && board[i][j-1] >0) live++;
            if(i+1 < m && board[i+1][j] >0) live++;
            if(j+1 < n && board[i][j+1] >0) live++;
            if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] >0) live++;
            if(i+1 < m && j-1 >= 0 && board[i+1][j-1] >0) live++;
            if(i-1 >= 0 && j+1 < n && board[i-1][j+1] >0) live++;
            if(i+1 < m && j+1 < n && board[i+1][j+1] >0) live++;
            
            if(board[i][j] == 0) board[i][j] = -live;
            else {//if live == 0, may miss the status if original is 1
                if(live == 0) board[i][j] = 1;
                else board[i][j] = live;
            }
        }
    }
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 2 || board[i][j] == 3 || board[i][j] == -3) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
}
};
