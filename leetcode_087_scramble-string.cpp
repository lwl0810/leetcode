//https://leetcode.com/problems/scramble-string/

class Solution {
public:
//recursion
bool isScrambleHelper(string s1, string s2){
	int sz = s1.length(), sz2 = s2.length();
    if(sz != sz2) return false;
    if(s1 == s2) return true;
	int cnt[26] = {0};
	for(int i = 0; i < sz; ++i){
	    cnt[s1[i]-'a']++;
	    cnt[s2[i]-'a']--;
	}
	for(int i = 0; i < 26; ++i){
	    if(cnt[i] != 0) return false;
	}
	for(int i = 1; i < sz; ++i){
	    if(isScrambleHelper(s1.substr(0, i), s2.substr(0, i)) && isScrambleHelper(s1.substr(i), s2.substr(i))) return true;
	    if(isScrambleHelper(s1.substr(0, i), s2.substr(sz-i)) && isScrambleHelper(s1.substr(i), s2.substr(0, sz-i))) return true;
	}
	return false;
}

/*
//recursion and array dp to maintain intermedia result
void isScrambleHelper(string s1, string s2, int i, int j, int len, vector<vector<vector<int>>>& dp){
    string t1 = s1.substr(i, len), t2 = s2.substr(j, len);
    if(t1 == t2){
        dp[len][i][j] = 1;
        return;
    }
	int cnt[26] = {0};
	for(int k = 0; k < len; ++k){
	    cnt[t1[k]-'a']++;
	    cnt[t2[k]-'a']--;
	}
	for(int k = 0; k < 26; ++k){
	    if(cnt[k] != 0){
	        dp[len][i][j] = -1;
	        return;
	    }
	}
	for(int k = 1; k < len; ++k){
	    if(dp[k][i][j] == 0) isScrambleHelper(s1, s2, i, j, k, dp);
	    if(dp[len-k][i+k][j+k] == 0) isScrambleHelper(s1, s2, i+k, j+k, len-k, dp);
	    if(dp[k][i][j] == 1 && dp[len-k][i+k][j+k] == 1){
	        dp[len][i][j] = 1; return;
	    }
	    if(dp[k][i][j+len-k] == 0) isScrambleHelper(s1, s2, i, j+len-k, k, dp);
	    if(dp[len-k][i+k][j] == 0) isScrambleHelper(s1, s2, i+k, j, len-k, dp);
	    if(dp[k][i][j+len-k] == 1 && dp[len-k][i+k][j] == 1){
	        dp[len][i][j] = 1; return;
	    }
	}
	dp[len][i][j] = -1;
	return;
}

bool isScramble(string s1, string s2){
    int sz = s1.length(), sz2 = s2.length();
    if(sz != sz2) return false;
    vector<vector<vector<int>>> dp(sz+1, vector<vector<int>>(sz, vector<int>(sz, 0)));
    isScrambleHelper(s1, s2, 0, 0, sz, dp);
    return dp[sz][0][0] == 1;
}
*/

/*
//time O(n^4), space O(n^3)
bool isScramble(string s1, string s2) {
    int sz = s1.length(), sz2 = s2.length();
    if(sz != sz2) return false;
    //1st degree: string length, 2nd degree: begin index of s1's substring, 3rd degree: begin index of s2's substring.
    //dp[len][i][j] stands for: s1.substr(i, len) and s2.substr(j, len) is scramble or not
    vector<vector<vector<bool>>> dp(sz+1, vector<vector<bool>>(sz, vector<bool>(sz, false)));
    for(int len = 1; len <= sz; ++len){
        for(int i = 0; i+len <= sz; ++i){
            for(int j = 0; j+len <= sz; ++j){
                if(s1.substr(i, len) == s2.substr(j, len)){
                    dp[len][i][j] = true;
                    continue;
                }
                for(int k = 1; k < len; ++k){
                    if(dp[k][i][j] && dp[len-k][i+k][j+k] || dp[k][i][j+len-k] && dp[len-k][i+k][j])
                        dp[len][i][j] = true;
                }
            }
        }
    }
    return dp[sz][0][0];
}
*/
};
