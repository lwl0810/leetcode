//https://leetcode.com/problems/gas-station/
class Solution {
public:
//time O(n), space O(1)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sz = gas.size(), start = 0, cur = 1;
    if(sz == 0) return -1;
    int remain = gas[0] - cost[0];
    if(sz == 1) return remain < 0 ? -1 : 0;
    while (cur%sz != start) {
        if(remain < 0) {
            start = cur;
            remain = 0;
            if(start >= sz) return -1;
        }
        remain += gas[cur%sz] - cost[cur%sz];
        cur++;
    }
    return remain < 0 ? -1 : start;
}
};
