//http://www.cnblogs.com/jcliBlogger/p/5015959.html
/*
Sparse Matrix Multiplication
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.

Example:
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
//time O(m*n*k) space O(m*n)
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	int ra = A.size(), ca = A[0].size(), rb = B.size(), cb = B[0].size();
	vector<vector<int>> C(ra, vector<int>(cb, 0)); //row num is A's row num, col num is B's col num
	for(int i = 0; i < ra; ++i){
		for(int j = 0; j < cb; ++j){
			for(int k = 0; k < ca; ++k){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
	
	// imporved on upper version, this is a math solution
    // for(int i = 0; i < ra; i++){
    //     for(int k = 0; k < ca; k++){
    //         if(A[i][k] != 0)
    //             for(int j = 0; j < cb; j++){
    //                 C[i][j] += A[i][k] * B[k][j];
    //             }
    //     }
    // }
    // return C
}
};
