//https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
//time: O(logdivisor(dividend))
int divide(int dividend, int divisor) {
    int sign = 0;
    if(dividend >= 0 && divisor >= 0 || dividend < 0 && divisor < 0) sign = 1;
    else sign = -1;
    long ldividend = labs(dividend), ldivisor = labs(divisor);
    vector<long> v;
    long tmp = ldivisor;
    while(tmp <= ldividend){
        v.push_back(tmp);
        tmp += tmp;
    }
    long res = 0;
    for(int i = v.size()-1; i >=0; --i){
        res = res << 1;
        if(v[i] <= ldividend){
            res = res | 1;
            ldividend -= v[i];
        }
    }
    res *= sign;
    if(res > INT_MAX || res < INT_MIN) return INT_MAX;
    return res;
}
};
