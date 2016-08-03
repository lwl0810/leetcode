//http://www.cnblogs.com/jcliBlogger/p/4870514.html
/*
Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between 
a letter in pattern and a non-empty substring in str.
Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false. 
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution{
public:
bool match(unordered_map<char, string>& um, unordered_set<string>& us, string& pattern, string& str, int i, int j) {
	int plen = pattern.length(), slen = str.length();
	if(i == plen && j == slen) return true;
	if(i == plen || j == slen) return false;
	char p = pattern[i];
	//current pattern char has already matched a string
	if(um.find(p) != um.end()){
		string s = um[p];
		if(s != str.substr(j, s.length())) return false;
		return match(um, us, pattern, str, i+1, j+s.length());
	}
	//find a match string for current pattern char
	for(int k = j; j < slen; ++j){
		string s = str.substr(j, k-j+1);
		if(us.find(s) != us.end()) continue;
		us.insert(s);
		um[p] = s;
		if(match(um, us, pattern, str, i+1, k+1)) return true;
		um.erase(p);
		us.erase(s);
	}
	return false;
}

bool wordPatternMatch(string pattern, string str) {
	unordered_map<char, string> um;
	unordered_set<string> us;
	return match(um, us, pattern, str, 0, 0);
}
};
