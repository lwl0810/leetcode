//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
bool solve (vector<vector<char>>& board, int i, int j, 
            vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<vector<bool>>>& squares){
    if(j == 9){
        i++;
        j = 0;
    }
    if(i == 9) return true;
    if(board[i][j] != '.') return solve(board, i, j+1, rows, cols, squares);
    for(int c = 1; c <= 9; c++){
        if(rows[i][c] || cols[j][c] || squares[i/3][j/3][c]) continue;
        board[i][j] = c + '0';
        rows[i][c] = true;
        cols[j][c] = true;
        squares[i/3][j/3][c] = true;
        if(solve(board, i, j+1, rows, cols, squares)) return true;;
        rows[i][c] = false;
        cols[j][c] = false;
        squares[i/3][j/3][c] = false;
    }
    board[i][j] = '.';
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> rows(9, vector<bool>(10, false));
    vector<vector<bool>> cols(9, vector<bool>(10, false));
    vector<vector<vector<bool>>> squares(3, vector<vector<bool>>(3, vector<bool>(10, false)));
    
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                rows[i][board[i][j]-'0'] = true;
                cols[j][board[i][j]-'0'] = true;
                squares[i/3][j/3][board[i][j]-'0'] = true;
            }
        }
    }
    solve(board, 0, 0, rows, cols, squares);
}
};
