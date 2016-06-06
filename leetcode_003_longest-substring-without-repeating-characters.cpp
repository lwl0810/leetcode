//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
//time: O(n), space: O(n)
//maintain a map key:character, value:index of the character. maintain two pointer
//once meet a unique character, caculate the length.
//meet a duplicated character, delete the character in map between start pointer and the duplicated index
int lengthOfLongestSubstring1(string s) {
    int i = 0, j = 0, res = 0;
    unordered_map<char, int> um;
    while(j < s.length()) {
        if(um.find(s[j]) == um.end()) {
            um[s[j]] = j;
            res = max(res, j - i + 1);
        }else {
            while(i <= um[s[j]]) {
                um.erase(s[i++]);
            }
            um[s[j]] = j;
        }
        j++;
    }
    return res;
}

//can using int[128] instead of unordered_map
//do not need to delete the character from map, just validate the index of each character should greater than pointer i
int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, res = 0;
    int um[128];
    memset(um, -1, sizeof(um));
    while(j < s.length()) {
        if(um[s[j]] != -1 && um[s[j]] >= i) {
            i = um[s[j]] + 1;
        }else {
            res = max(res, j - i + 1);
        }
        um[s[j]] = j;
        j++;
    }
    return res;
}
};
