//http://blog.csdn.net/xudli/article/details/42340867
/*
Description:ONE EDIT DISTANCE
Given two strings S and T, determine if they are both one edit distance apart.
*/


class Solution {
public:
bool isOneEditDistance(string s, string t){
	int ls = s.length(), lt = t.length();
	int edit = ls - lt;
	bool edited = false;
	if(edit > 1 || edit < -1) return false;
	for(int is = 0, it = 0; is < ls && it < lt; ){
		if(s[is] != t[it]){
			if(edited) return false;
			edited = true;
			if(edit == 0) { ++is; ++it; }
			if(edit == 1) { ++is; }
			if(edit == -1){ ++it; }
			}
		}else{
			++is;
			++it;
		}
	}
	return edited;
}
};
