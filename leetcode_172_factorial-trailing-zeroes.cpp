//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
////n! = (5*K) * (5*(K-1)) * (5*(K-2)) * ... * 5 * A
//f(n!) = g(n!) = g(5^K * K! * A) = K + g(K!) = K + f(K!), K=n / 5
//f(1000!) = 200 + f(200!) = 200 + 40 + f(40!) = 240 + 8 + f(8!) = 248 + 1 + f(1) =249
int trailingZeroes(int n) {
    int zeros = 0;
    while(n > 0) {
        n = n / 5;
        zeros += n;
    }
    return zeros;
}
};
