//https://leetcode.com/problems/word-break-ii/

class Solution {
public:
void helper(string s, vector<string>& res, string cur, int pos, unordered_set<string>& wordDict ){
    if(pos==s.length()){
        cur.pop_back();
        res.push_back(cur);
        return;
    }
    for(int i=pos; i<s.length(); i++){
        string word=s.substr(pos, i-pos+1);
        if(wordDict.find(word)!=wordDict.end()){
            string tmp=cur+word+" ";
            helper(s, res, tmp, i+1, wordDict);
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict){
    vector<string> res;
    int k=s.length();
	//find there must have at least one result, avoid nosense running into recursion
    vector<bool> flag(k+1,false);
    flag[k] = true;
    for (int i=k-1;i>=0;i--){
        int j=i;
        while(j<=k-1){
            if (flag[j+1] && wordDict.find(s.substr(i,j-i+1))!=wordDict.end()){
                flag[i] = true;
                break;
            }
            j++;
        }
    } 
    if (flag[0]==false) return res;   // no possible solution if flag[0]==false
    helper(s, res, "", 0, wordDict);
    return res;
}
