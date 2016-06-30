//https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int k) {
        int res = 0;
        //A(k,k)*C(n,k)
        //Let f(k) = count of numbers with unique digits with length equals k.
        //f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
        if(k == 0) return 1;
        if(k == 1) return 10;
        for(int i = 2; i <= k; ++i){
            int tmp = 1;
            for(int j = 9-i+2; j <= 9; ++j){
                tmp *= j;
            }
            res += tmp*9;
        }
        res += 10;
        return res;
    }
};
