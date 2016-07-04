//https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
void preProcess(vector<vector<bool>>& dp, const string& s){
    int k = 0, l = 0, r = 0, len = s.length();
    while(k < len){
        l = k; r = k; dp[k][k] = true;
        while(r+1 < len && s[r+1] == s[r]){
            dp[l][r+1] = true;
            ++r;
        }
        ++k;
        while(l > 0 && r < len-1 && s[l-1] == s[r+1]){
            --l;
            ++r;
			dp[l][r] = true;
        }
    }
}

void nextPartition(vector<vector<string>>& res, vector<vector<bool>>& dp, vector<string>& cur, string s, int pos){
    int len = s.length();
    if(pos == len){
        res.push_back(cur);
        return;
    }
    for(int i = pos; i < len; ++i) {
        if(dp[pos][i]){
            cur.push_back(s.substr(pos, i-pos+1));
            nextPartition(res, dp, cur, s, i+1);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    int len = s.length();
    vector<vector<string>> res;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    vector<string> cur;
    
    preProcess(dp, s);
    nextPartition(res, dp, cur, s, 0);
    return res;
}
};
