//https://leetcode.com/problems/additive-number/

class Solution {
public:

bool numValid(string n){
    if(n.length() > 1 && n[0] == '0') return false;
    return true;
}

//pay attention to the range of num may exceed INT_MAX
string addNums(string s1, string s2){
    long n1 = stoi(s1), n2 = stoi(s2);
    return to_string(n1 + n2);
}

bool isAdditiveNumHelper(string s1, string s2, string num){
    if(num.length() == 0) return true;
    string s = addNums(s1, s2);
    if(num.substr(0, s.length()) == s){
        if(isAdditiveNumHelper(s2, s, num.substr(s.length())))
            return true;
    }
    return false;
}

//time O(n*(n/2)^2)
bool isAdditiveNumber(string num) {
    int len = num.length();
    for(int l1 = 1; l1 <= len/2; ++l1){
        string s1 = num.substr(0, l1);
        if(!numValid(s1)) break;
        for(int l2 = 1; l1+l2+max(l1,l2) <= len; ++l2){
            string s2 = num.substr(l1, l2);
            if(!numValid(s2)) break;
            string s = addNums(s1, s2);
            if(s == num.substr(l1+l2, s.length())){
                if(isAdditiveNumHelper(s2, s, num.substr(l1+l2+s.length())))
                    return true;
            }
        }
    }
    return false;
}

};
