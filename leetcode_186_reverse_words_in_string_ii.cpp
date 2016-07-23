//http://betterpoetrythancode.blogspot.com/2015/02/reverse-words-in-string-ii-leetcode.html
/*
Reverse Words in a String II
Question: Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Could you do it in-place without allocating extra space?
*/
//time O(n), space O(1)
class Solution{
public:
void reverseWords(string &s){
	reverse(s.begin(), s.end());
	int n = s.length();
    int start = 0, end = 0;
    while(start < n){
        end = start;
        while(end < n && s[end] != ' ') ++end;
        reverse(s.begin()+start, s.begin()+end);
        start = end+1;
    }
}
};
