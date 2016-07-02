//https://leetcode.com/problems/powx-n/

class Solution {
public:
double myPow(double x, int n) {
    double res = 1, tmp = x;
	int mask = 1;
	unsigned int n1=abs(n); //in case n = INT_MIN
	while(n1){
		if(n1 & mask) res *= tmp;
		n1 = n1 >> 1;
		tmp *= tmp;
	}
	if(n < 0) res = 1/res;
	return res;
}
};
