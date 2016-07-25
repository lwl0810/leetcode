//http://www.cnblogs.com/jcliBlogger/p/4752065.html
/*
Palindrome Permutation II
Given a string s, return all the palindromic permutations (without duplicates) of it. 
Return an empty list if no palindromic permutation could be form.

For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].
Hint:
If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
*/

class Solution{
public:
void permutation(vector<string>& res, string cur, unordered_map<char, int>& um, int len){
	if(cur.length() == len){
		res.push_back(cur);
		return;
	}
	for(unordered_map<char, int>::iterator it = um.begin(); it != um.end(); ++it){
		if(it->second == 0) continue;
		char ch = it->first;
		it->second -= 2;
		permutation(res, ch+cur+ch, um, len);
		um[ch] += 2;
	}
}

vector<string> generatePalindromes(string s){
	unordered_map<char, int> um;
	vector<string> res;
	string str = "";
	for(int i = 0; i < s.length(); ++i) um[s[i]]++;
	//check if palidrome can be generated?
	char oddChar = 0;
	for(unordered_map<char, int>::iterator it = um.begin(); it != um.end(); ++it){
		if(it->second % 2 != 0){
			if(oddChar == 0){
				oddChar = it->first;
				it->second -= 1;
			}else return res;
		}
	}
	string cur = oddChar == 0? "": string(1, oddChar);
	permutation(res, cur, um, s.length());
	return res;
}
};
