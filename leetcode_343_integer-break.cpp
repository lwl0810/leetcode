//https://leetcode.com/problems/integer-break/

class Solution {
public:
int integerBreak(int n) {
    if(n == 1 || n == 2) return 1;
    if(n == 3) return 2;
    int div3 = n / 3;
    int mod3 = n % 3;
    if(mod3 == 0) return pow(3, div3);
    if(mod3 == 1) return pow(3, div3-1) * 4;
    return pow(3, div3-1) * 6;
}
};
