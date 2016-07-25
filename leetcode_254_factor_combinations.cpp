//http://www.cnblogs.com/airwindow/p/4822572.html
/*
Numbers can be regarded as product of its factors. For example, 
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors. 
Note: 
Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2]. 
You may assume that n is always positive. 
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]

input: 37
output: 
[]

input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
class Solution{
public:
void factorCombinations(vector<vector<int>>& res, vector<int>& cur, int factor, int remain){
	if(remain == 1){
		if(cur.size() > 1) res.push_back(cur);
		return;
	}
	for(int i = factor; i <= remain; ++i){
		if(remain % i != 0) continue;
		cur.push_back(i);
		factorCombinations(res, cur, i, remain/i);
		cur.pop_back();
	}
}

vector<vector<int>> getFactors(int n){
	vector<vector<int>> res;
	vector<int> cur;
	factorCombinations(res, cur, 2, n);
	return res;
}
};
