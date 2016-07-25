//http://www.cnblogs.com/jcliBlogger/p/4748554.html
/*
Palindrome Permutation
Given a string, determine if a permutation of the string could form a palindrome.
For example,
"code" -> False, "aab" -> True, "carerac" -> True.
Hint:
Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
*/

class Solution{
public:
//time O(n), space O(n)
bool canPermutePalindrome(string s){
	unordered_set<char> us;
	for(int i = 0; i < s.length(); ++i){
		if(us.find(s[i]) != us.end()) us.erase(s[i]);
		else us.insert(s[i]);
	}
	if(us.size() > 1) return false;
	return true;
}
};
