//https://leetcode.com/problems/valid-number/

class Solution {
public:
//time O(n), space O(1)
bool isNumber(string s) {
	int len = s.length();
	if(len == 0)return false;
	int i = 0;
	int cntDot = 0, cntNum = 0;
	//eliminate spaces
	while(s[i] == ' ') i++;
	
	if(s[i] == '+' || s[i] == '-') i++;
	while(isdigit(s[i]) || s[i] == '.'){
		if(s[i] == '.') cntDot++;
		else cntNum++;
		if(++i >= len) break;
	}
	//more than one decimal point or no number character
	if(cntDot > 1 || cntNum < 1) return false;
	
	if(s[i] == 'e'){
		i++;
		cntNum = 0; cntDot = 0;
		if(s[i] == '+' || s[i] == '-') i++;
		while(isdigit(s[i]) || s[i] == '.'){
			if(s[i]=='.') cntDot++;
			else cntNum++;
			if(++i >= len) break;
		}
		//cannot contain decimal point
		if(cntDot > 0 || cntNum < 1) return false;
	}
	//eliminate spaces
	while(i < len && s[i] == ' ') i++;
    return i == len;
}
};
