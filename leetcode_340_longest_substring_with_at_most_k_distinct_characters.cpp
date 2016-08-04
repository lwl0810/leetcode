//http://www.cnblogs.com/grandyang/p/5351347.html
/*
Longest Substring with At Most K Distinct Characters
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
*/

class Solution {
public:
//time O(n) space O(k)
int lengthOfLongestSubstringKDistinct(string s, int k) {
	unordered_map<char, int> um;
	int maxLen = 0;
	for(int l = 0, r = 0; r < s.length(); ++r) {
		um[s[r]]++;
		while(um.size() > k){
			if(um[s[l]] == 1) um.erase[s[l]];
			else um[s[l]]--;
			++l;
		}
		maxLen = max(maxLen, r-l+1);
	}
	return maxLen;
}
};
