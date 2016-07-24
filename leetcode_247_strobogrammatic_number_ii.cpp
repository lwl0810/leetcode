//http://blog.csdn.net/pointbreak1/article/details/48763175
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
Hint:
Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
*/

class Solution{
public:
void strobogrammaticHelper(vector<string>& res, string strobo, string cur, int pos, int len, int isOdd){
	if(cur.length() == len){
		string secHalf = cur;
		reverse(secHalf.begin(), secHalf.end());
		for(int i = 0; i < len; ++i){
			if(secHalf[i] == '6') secHalf[i] = '9';
			else if(secHalf[i] == '9') secHalf[i] = '6';
		}
		if(isOdd){
			for(int i = 0; i < 3; ++i){
				res.push_back(cur + strobo[i] + secHalf);
			}
		}else res.push_back(cur + secHalf);
		return;
	}
	
	for(int i = pos; i < strobo.length(); ++i){
		if(cur.length() == 0 && i == 0) continue;
		cur.push_back(strobo[i]);
		strobogrammaticHelper(res, strobo, cur, i, len, isOdd);
		cur.pop_back();
	}
}
	
vector<string> findStrobogrammatic(int n){
	vector<string> res;
	int len = n/2, isOdd = n%2;
	string strobo = "01869";
	strobogrammaticHelper(res, strobo, "", 0, len, isOdd);
	return res;
}
};
