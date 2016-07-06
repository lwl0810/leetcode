//https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
NumMatrix(vector<vector<int>> &matrix) {
    m = matrix.size();
    if(m == 0) n = 0;
    else n = matrix[0].size();
    sum = matrix;
    int pre = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int plus1=0, plus2=0, minus=0;
			if(i>0) plus1=sum[i-1][j];
			if(j>0) plus2=sum[i][j-1];
			if(i>0 && j>0) minus=sum[i-1][j-1];
			//do not miss add the matrix[i][j]
			sum[i][j]=sum[i][j] + plus1+plus2-minus;
        }
    }
}

int sumRegion(int row1, int col1, int row2, int col2) {
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    sum1 = sum[row2][col2];
    if(row1 > 0) sum2 = sum[row1-1][col2];
    if(col1 > 0) sum3 = sum[row2][col1-1];
    if(row1 > 0 && col1 > 0) sum4 = sum[row1-1][col1-1];
    return sum1 - sum2 - sum3 + sum4;
}

private:
    vector<vector<int>> sum;
    int m, n;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
