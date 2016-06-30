//https://leetcode.com/problems/sum-of-two-integers/
class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0 || b == 0) return a == 0? b: a;
        int c = a ^ b;
        int d = (a & b)<<1;
        return getSum(c, d);
    }
};
