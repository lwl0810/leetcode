//https://leetcode.com/problems/compare-version-numbers/
class Solution {
public:
//1.0.1 & 1, 1.0 & 1
//time O(n) space O(1)
int compareVersion(string version1, string version2) {
    int s1 = 0, s2 = 0, e1 = 0, e2 = 0, v1 = 0, v2 = 0;
    while(1) {
        if(s1 < 0) v1 = 0;
        else {
            e1 = version1.find_first_of('.', s1);
            v1 = stoi(version1.substr(s1, e1-s1));
        }
        if(s2 < 0) v2 = 0;
        else {
            e2 = version2.find_first_of('.', s2);
            v2 = stoi(version2.substr(s2, e2-s2));
        }
        if(v1 > v2) return 1;
        else if(v1 < v2) return -1;
        if(e1 < 0 && e2 < 0) break;
        s1 = e1 < 0 ? -1 : e1+1;
        s2 = e2 < 0 ? -1 : e2+1;
    }
    return 0;
}
};
