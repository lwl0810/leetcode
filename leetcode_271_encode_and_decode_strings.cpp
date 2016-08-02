//http://www.cnblogs.com/jcliBlogger/p/4768875.html
/*
Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
} 

So Machine 1 does:
string encoded_string = encode(strs);
and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.
Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

class Solution{
public:
// Encodes a list of strings to a single string.
//strlen + "#" + string
string encode(vector<string>& strs) {
	int sz = strs.size();
	string res = "";
	for(int i = 0; i < sz; ++i){
		int len = strs[i].length();
		res += to_string(len) + "#" + strs[i];
	}
	return res;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
	vector<string> res;
	int i = 0, len = s.length();
	while(i < len){
		int pos = s.find_first_of('#', i);
		int slen = stoi(s.substr(i, pos));
		res.push_back(s.substr(pos+1, slen));
		i += pos + slen + 1;
	}
	return res;
}
};
