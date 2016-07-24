//http://blog.csdn.net/pointbreak1/article/details/48780345
/*
Group Shifted Strings
Given a string, we can "shift" each of its letter to its successive letter, 
for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, 
group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.

["eqdf", "qcpr"]。
((‘q’ - 'e') + 26) % 26 = 12, ((‘d’ - 'q') + 26) % 26 = 13, ((‘f’ - 'd') + 26) % 26 = 2
((‘c’ - 'q') + 26) % 26 = 12, ((‘p’ - 'c') + 26) % 26 = 13, ((‘r’ - 'p') + 26) % 26 = 2
*/

class Solution{
public:
string encode(string s){
	if(s.length() == 0) return "-1";
	if(s.length() == 1) return "0";
	string code = "";
	for(int i = 1; i < s.length(); ++i){
		code += to_string((s[i]-s[i-1]+26)%26) + ",";
	}
	return code;
}

vector<vector<string>> groupStrings(vector<string>& strings){
	unordered_map<string, vector<string>> um;
	for(int i = 0; i < strings.size(); ++i){
		string code=encode(strings[i]);
		um[code].push_back(strings[i]);
	}
	vector<vector<string>> res;
	for(unordered_map<string, vector<string>>::iterator it = um.begin(); it != um.end(); ++it){
		sort(it->second.begin(), it->second.end());
		res.push_back(it->second);
	}
	return res;
}
};
