//https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
//dynamic programming(faster)
//time O(n), space O(n)
int longestValidParentheses(string s) {
    int len = s.length(), res = 0;
    vector<int> dp(len, -1);
    for(int i = 1; i < len; ++i){
        if(s[i] == ')'){
            //check the current substring end with s[i] is valid or not
            if(dp[i-1] == -1){
                if(s[i-1] == '(') dp[i] = i-1;
            }else{
                if(s[dp[i-1]-1] == '(') dp[i] = dp[i-1]-1;
            }
            //check the substring before current substring is valid or not
            if(dp[i] > 0 && dp[dp[i]-1] != -1) dp[i] = dp[dp[i]-1];
        }
    }
    for(int i = 1; i < len; ++i){
        if(dp[i] != -1){
            res = max(res, i-dp[i]+1);
        }
    }
    return res;
}

//time: O(n), space O(n)
// int longestValidParentheses(string s) {
//     int res = 0;
//     stack<int> ps; //store the index of '('
//     ps.push(-1); //push -1 as sentinel
//     for(int i = 0; i < s.length(); ++i){
//         if(s[i] == ')' && ps.top() != -1 && s[ps.top()] == '('){
//             ps.pop();
//             res = max(res, i-ps.top());
//         }else ps.push(i);
//     }
//     return res;
// }
};
