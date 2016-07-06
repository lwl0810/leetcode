//https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
//time O(n*k), space O(n+k)
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ugly(n, INT_MAX);
    vector<int> pos(primes.size(), 0);
    ugly[0] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < primes.size(); ++j){
            ugly[i] = min(ugly[pos[j]]*primes[j], ugly[i]);
        }
        for(int j = 0; j < primes.size(); ++j){
            if(ugly[i] == ugly[pos[j]]*primes[j]) pos[j]++;
        }
    }
    return ugly[n-1];
}
};
