//https://leetcode.com/problems/valid-perfect-square/
class Solution {
public:
//time: O(logn), space O(1)
//binary search
bool isPerfectSquare(int num) {
    long long n = num, s = 0, e = n, m = 0, product = 0;
    while(s <= e){
        m = s + (e-s)/2;
        product = m * m;
        if(product == n) return true;
        else if(product > n) e = m - 1;
        else s = m + 1;
    }
    return false;
}
};
