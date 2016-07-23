//http://www.danielbit.com/blog/puzzle/leetcode/leetcode-longest-substring-with-at-most-two-distinct-characters
/*
Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3.
*/

class Solution {
public:
//time O(n), space O(1)
//i maintain the start index of sliding window, end-1 is the end of the window. ch is index of another distinct character
int lengthOfLongestSubstringTwoDistinct(string s){
	int len = s.length(), longest = 0;
	int start = 0, ch = -1;
	for(int end = 1; end < len; ++end){
		if(s[end] == s[end-1]) continue;
		if(ch >= 0 && s[ch] != s[end]){
			longest = max(longest, end-1-start+1);
			start = ch+1;
		}
		ch = end-1;
	}
	return max(longest, len - start);
}
};
