//https://leetcode.com/problems/reverse-integer/
class Solution {
public:
//time and space: O(1)
int reverse(int x) {
    long xl = abs(x), res = 0;
    int sign = x < 0? -1: 1;
    while(xl) {
        res = res*10 + xl%10;
        xl /= 10;
    }
    if(sign < 0) res *= -1;
    if(res > INT_MAX || res < INT_MIN) return 0;
    return (int)res;
}
};
