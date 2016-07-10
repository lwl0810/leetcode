//https://leetcode.com/problems/super-pow/

class Solution {
public:
//time O(10*n)
int superPow(int a, vector<int>& b) {
    int sz = b.size();
    if(sz == 0) return 1;
    //a^0 mod 1337, a^1 mod 1337, a^2 mod 1337, ..., a^10 mod 1337
    vector<long> aPowN(11, 1);
    for(int i = 1; i <= 10; ++i){
        aPowN[i] = (aPowN[i-1] * a) % 1337;
    }
    
    //aPow10: a^10 mod 1337, a^100 mod 1337, a^1000 mod 1337 ...
    long res = aPowN[b[sz-1]], aPow10 = aPowN[10];
    for(int i = sz-2; i >= 0; --i){
        long tmp = 1;
        for(int j = 0; j < b[i]; ++j){
            tmp = (tmp * aPow10) % 1337;
        }
        res = (res * tmp) % 1337;
        for(int j = 0; j < 10-b[i]; ++j){
            tmp = (tmp * aPow10) % 1337;
        }
        aPow10 = tmp;
    }
    return res;
}
};
