//https://leetcode.com/problems/multiply-strings/

class Solution {
public:
//only deal with carry at the final step
//time and space O(n^2)
string multiply(string num1, string num2) {
    vector<vector<int>> multiplies;
    for(int i = num1.length()-1; i >= 0; --i){
        vector<int> tmp;
        for(int j = num2.length()-1; j >= 0; --j){
            tmp.push_back((num1[i]-'0')*(num2[j]-'0'));
        }
        multiplies.push_back(tmp);
    }
    
    for(int i = 1; i < multiplies.size(); ++i){
        for(int j = 0; j < multiplies[i].size(); ++j){
            if(j+i >= multiplies[0].size()) multiplies[0].push_back(multiplies[i][j]);
            else multiplies[0][j+i] = multiplies[0][j+i] + multiplies[i][j];
        }
    }
    
    string res = "";
    int carry = 0;
    for(int i = 0; i < multiplies[0].size(); ++i){
        multiplies[0][i] += carry;
        carry = multiplies[0][i] / 10;
        res = (char)((multiplies[0][i] % 10) + '0') + res;
    }
    if(carry) res = to_string(carry) + res;
    if(res[0] == '0') res = "0";
    return res;
}
};
