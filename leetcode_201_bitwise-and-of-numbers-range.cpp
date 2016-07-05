//https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
//find the common prefix of m and n
int rangeBitwiseAnd(int m, int n) {
    unsigned int mask = 0x80000000;
    int res = 0;
    for(int i = 0; i < 32; ++i){
        if((m & mask) == (n & mask)) res |= mask & m;
        else break;
        mask >>= 1;
    }
    return res;
}
};
