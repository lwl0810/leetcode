//https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
//time O(n), space O(1)
string convert(string s, int numRows) {
    if(numRows <= 1) return s;
    string res = "";
    int i = 0, len = s.length();
    while (i < numRows) {
        int j = i;
        while(j < len) {
            res += s[j];
            if(i > 0 && i < numRows-1) {
                int index = j-i+numRows + (numRows-2)-(i-1)-1;
                if(index < len) res += s[index];
            }
            j += numRows + numRows - 2;
        }
        i++;
    }
    return res;
}
};
