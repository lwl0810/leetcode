//https://leetcode.com/problems/valid-anagram/

class Solution {
public:
//time O(n), space O(1)
bool isAnagram(string s, string t) {
    int sl = s.length(), tl = t.length();
    if(sl != tl) return false;
    
    int sm[26] = {0}, tm[26] = {0};
    for(int i = 0; i < sl; ++i){
        sm[s[i] - 'a']++;
        tm[t[i] - 'a']++;
    }
    for(int i = 0; i < 26; ++i){
        if(tm[i] != sm[i]) return false;
    }
    return true;
}
};
