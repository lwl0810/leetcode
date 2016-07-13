//https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
void placeQueen(int row, unsigned column, unsigned diagonal, unsigned back_diagonal) {
    if(row == n){
        cnt++; return;
    }
    for(int i = 0; i < n; ++i){
        unsigned int cur = 1 << i;
        if(cur & column || cur & diagonal || cur & back_diagonal) continue;
        placeQueen(row+1, column|cur, (diagonal|cur)>>1, (back_diagonal|cur)<<1);
    }
}

int totalNQueens(int n) {
    this->n = n;
    cnt = 0;
    placeQueen(0, 0, 0, 0);
    return cnt;
}

private:
int cnt, n;
};
