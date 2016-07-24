//http://www.cnblogs.com/grandyang/p/5203228.html
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/

class Solution{
public:
void strobogrammaticHelper(string& low, string& high, string cur, int& cnt){
	if(cur.length() >= low.length() && cur.length() <= high.length()){
		if(cur.length() == low.length() && cur < low || cur.length() == high.length() && cur > high) return;
		if(!(cur.length() > 1 && cur[0] == '0')) ++cnt;
	}
	if(cur.length() + 2 > high.length()) return;
	strobogrammaticHelper(low, high, '0' + cur + '0', cnt);
	strobogrammaticHelper(low, high, '1' + cur + '1', cnt);
	strobogrammaticHelper(low, high, '8' + cur + '8', cnt);
	strobogrammaticHelper(low, high, '6' + cur + '9', cnt);
	strobogrammaticHelper(low, high, '9' + cur + '6', cnt);
}

int strobogrammaticInRange(string low, string high){
	int cnt = 0;
	strobogrammaticHelper(low, high, "", cnt);
	strobogrammaticHelper(low, high, "0", cnt);
	strobogrammaticHelper(low, high, "1", cnt);
	strobogrammaticHelper(low, high, "8", cnt);
	return cnt;
}
};
