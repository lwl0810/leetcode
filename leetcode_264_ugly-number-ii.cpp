//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
//time O(3n)
int nthUglyNumber(int n) {
    int ugly[n] = {INT_MAX}, pos[3] = {0};
    ugly[0] = 1;
    int tmp2, tmp3, tmp5;
    for(int i = 1; i < n; ++i){
        tmp2 = 2 * ugly[pos[0]];
        tmp3 = 3 * ugly[pos[1]];
        tmp5 = 5 * ugly[pos[2]];
        ugly[i] = min(tmp2, min(tmp3, tmp5));
        if(ugly[i] == tmp2) pos[0]++;
        if(ugly[i] == tmp3) pos[1]++;
        if(ugly[i] == tmp5) pos[2]++;
    }
    return ugly[n-1];
}
};
