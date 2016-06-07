//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
//expand around center
//time O(n^2), space O(1)
string longestPalindrome1(string s) {
    string res="";
    int i = 0, len = s.length(), maxlen = 0;
    while(i < len && len-i > maxlen/2) {
        int left = i, right = i;
        while(right < len && s[right+1] == s[i]) right++;
        i = right + 1;
        while(left > 0 && right < len-1 && s[left-1] == s[right+1]) {
            --left;
            ++right;
        }
        if(right-left+1 > maxlen) {
            maxlen = right-left+1;
            res = s.substr(left, maxlen);
        }
    }
    return res;
}



//Manacher's Algorithm： http://articles.leetcode.com/longest-palindromic-substring-part-ii/
//time O(n), space O(n)
//transform S into T.
//for example, S = "abba", T = "^#a#b#b#a#$".
//^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
    int len = s.length();
    if (len == 0) return "^$";
    string res = "^";
    for (int i = 0; i < len; ++i)
        res += "#" + s.substr(i, 1);
    res += "#$";
    return res;
}
 
string longestPalindrome(string s) {
    string t = preProcess(s);
    int len = t.length();
    vector<int> p(len, 0);
    int center = 0, right = 0;
    for (int i = 1; i < len-1; ++i) {
        int i_mirror = center - ( i - center);
        p[i] = (right > i)? min(right-i, p[i_mirror]) : 0;
        
        //attempt to expand palindrome centered at i
        while(t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
        //if palindrome centered at i expand past R, adjust center based on expanded palindrome.
        if(i+p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    
    //find the maximum element in p.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < len-1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
};
