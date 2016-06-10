//https://leetcode.com/problems/excel-sheet-column-title/
class Solution {
public:
//time O(1) space O(1)
string convertToTitle(int n) {
    string s;
	while(n) {
		s = char((n-1) % 26 + 'A') + s;
		n = (n-1) / 26;
	}
	return s;
}
};
