//https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
//time O(logn) space O(1)
class Solution {
public:
int firstBadVersion(int n) {
    int s = 1, e = n, m = 0;
    while(s <= e) {
        //maybe overflow if use (s+e)/2
        m = s + (e - s) / 2;
        if(!isBadVersion(m)) s = m + 1;
        else e = m - 1;
    }
    return s;
}
};
