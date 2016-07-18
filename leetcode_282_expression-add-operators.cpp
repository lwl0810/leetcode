//https://leetcode.com/problems/expression-add-operators/

class Solution {
public:
vector<string> addOperators(string num, int target) {
    vector<string> res;
    if(num.size() == 0)   return res;
    help(res, "", num, target, 0, 0, 0);
    return res;
}

void help(vector<string>& res, string path, string num, int target, int pos, long cur, long pre){
    if(pos == num.size()){
        if(cur == target) res.push_back(path);
        return;
    }
    for(int i = pos; i < num.size(); i++){
        /* corner-case-added-code */
        if(num[pos] == '0' && i > pos) break;
        string s = num.substr(pos, i-pos+1);
        long val = stol(s);
        if(pos == 0)  {
            help(res, s, num, target, i+1, val, val);
        }else{
            help(res, path + "+" + s, num, target, i+1, cur + val, val);
            help(res, path + "-" + s, num, target, i+1, cur - val, -val);
            //deal with the precedence of operators using pre
            help(res, path + "*" + s, num, target, i+1, cur - pre + pre * val, pre*val);
        }
    }
}
};
