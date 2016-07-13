//https://leetcode.com/problems/n-queens/

class Solution {
public:
void placeQueen(int row, unsigned column, unsigned diagonal, unsigned back_diagonal, vector<string>& board) {
    if(row == n){
        res.push_back(board); return;
    }
    for(int i = 0; i < n; ++i){
        unsigned int cur = 1 << i;
        if(cur & column || cur & diagonal || cur & back_diagonal) continue;
        board[row][i] = 'Q';
        placeQueen(row+1, column|cur, (diagonal|cur)>>1, (back_diagonal|cur)<<1, board);
        board[row][i] = '.';
    }
}

vector<vector<string>> solveNQueens(int n){
    this->n = n;
    string nDot(n, '.');
    vector<string> board(n, nDot);
    placeQueen(0, 0, 0, 0, board);
    return res;
}

private:
int cnt, n;
vector<vector<string>> res;
};
