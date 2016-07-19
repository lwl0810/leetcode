//https://leetcode.com/problems/palindrome-pairs/

class Solution {
public:
bool isPalindrome(const string& s){
    int l = 0, r = s.length()-1;
    while(l < r){
        if(s[l++] != s[r--]) return false;
    }
    return true;
}

//time O(wordsSize * wordLen^2) space O(wordsSize^2)
vector<vector<int>> palindromePairs(vector<string>& words) {
    int sz = words.size();
    vector<vector<int>> res;
    unordered_map<string, int> wordsIndex;
    for(int i = 0; i < sz; ++i){
        wordsIndex[words[i]] = i;
    }
    for(int i = 0; i < sz; ++i){
        string cur = words[i], target = "";
        int len = cur.length();
        //check the corner case that word[i] == ""
        if(len == 0) continue;
        for(int j = 0; j <= len; ++j){
            //add to the end
            if(isPalindrome(cur.substr(j))){
                target = cur.substr(0, j);
                reverse(target.begin(), target.end());
                if(target != cur && wordsIndex.find(target) != wordsIndex.end()){
                    vector<int> tmp(2, 0);
                    tmp[0] = i;
                    tmp[1] = wordsIndex[target];
                    res.push_back(tmp);
                }
            }
            //add to the head
            //avoid double count: for "abc" and "cba, avoid count both (add end) and (add head) when target == "abc" and "cba"
            if(j == 0) continue; 
            if(isPalindrome(cur.substr(0, j))){
                target = cur.substr(j);
                reverse(target.begin(), target.end());
                if(target != cur && wordsIndex.find(target) != wordsIndex.end()){
                    vector<int> tmp(2, 0);
                    tmp[0] = wordsIndex[target];
                    tmp[1] = i;
                    res.push_back(tmp);
                }
            }
        }
    }
    return res;
}
};
