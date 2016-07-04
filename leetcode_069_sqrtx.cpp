//https://leetcode.com/problems/sqrtx/

class Solution {
public:
//binary search
int mySqrt(int x) {
	if(x < 0) return INT_MIN;
    if(x == 0 || x == 1) return x;
    int left = 1, right = x, mid = 0, factor = 0;
    while (left <= right){
        mid = left + (right - left) / 2;
        factor = x / mid;
        if (mid == factor) return mid;
        else if(mid < factor) left = mid + 1;
		else right = mid - 1;
	}
	return right;
}

//Newton: n2=(n1+x/n1)/2
// int mySqrt(int x) {
// 	double n1=1, n2 = (n1 + x / n1) / 2;
// 	while(floor(n1) != floor(n2)){
// 		n1 = n2;
// 		n2 = (n1 + x  /n1) / 2;
// 	}
// 	return floor(n1);
// }
};
