//https://leetcode.com/problems/word-break/

class Solution {
public:
bool wordBreak(string s, unordered_set<string>& wordDict) {
    int len = s.length(), maxlen = 0, minlen = len;
    vector<bool> dp(len, false);
    
    unordered_set<string>::iterator it;
    for(it = wordDict.begin(); it != wordDict.end(); it++){
        int l = (*it).length();
        minlen = min(minlen, l);
        maxlen = max(maxlen, l);
    }
    
    for(int i = 0; i <= len-minlen; ++i){
        int j = minlen;
        while(j <= maxlen && i + j <= len){
            string tmp = s.substr(i, j);
            if((i == 0 || dp[i-1]) && wordDict.find(tmp) != wordDict.end()){
                dp[i+j-1]=true;
            }
            j++;
        }
        // while(dp[i] == false && j > 0){ i++; j--;}
        // if(j == 0)return false;
    }
    return dp[len-1];
}


/*
//recursion solution, using vector<int> dp maintain the intermedia result to avoid unnecessary compute
void wordbreakHelper(string s, unordered_set<string>& wordDict, vector<int>& dp, int pos){
    for(int i = minlen; i <= maxlen; ++i){
        if(pos - i < -1) break;
        string cur = s.substr(pos-i+1, i);
        if(wordDict.find(cur) != wordDict.end()){
            if(pos - i == -1){
                dp[pos] = 1;
                break;
            }
            if(dp[pos-i] == -1) continue;
            if(dp[pos-i] == INT_MIN){
                wordbreakHelper(s, wordDict, dp, pos-i);
            }
            if(dp[pos-i] == 1){
                dp[pos] = 1;
                break;
            }
        }
    }
    if(dp[pos] != 1) dp[pos] = -1;
}

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int len = s.length();
    maxlen = 0; minlen = len;
    vector<int> dp(len, INT_MIN);
    for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it){
        int curlen = (*it).length();
        minlen = min(minlen, curlen);
        maxlen = max(maxlen, curlen);
    }
    wordbreakHelper(s, wordDict, dp, len-1);
    return dp[len-1] == 1;
}

private:
int minlen, maxlen;
*/
};
