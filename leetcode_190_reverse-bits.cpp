//https://leetcode.com/problems/reverse-bits/
class Solution {
public:
//time O(1), space O(1)
uint32_t reverseBits(uint32_t n) {
    unsigned int mask1 = 0x80000000, mask2 = 0x00000001;
    while(mask1 > mask2) {
        if((mask1 & n) == 0 && (mask2 & n) != 0 || (mask1 & n) != 0 && (mask2 & n) == 0) {
            n ^= mask1;
            n ^= mask2;
        }
        mask1 = mask1 >> 1;
        mask2 = mask2 << 1;
    }
    return n;
}
};
