//https://leetcode.com/problems/largest-number/

bool mycomp(const string& a, const string& b){
    return a+b > b+a;
}

//time O(nlogn) space O(n)
class Solution {
public:
string largestNumber(vector<int>& nums) {
    string res = "";
    vector<string> s;
    for(int i = 0; i < nums.size(); ++i) 
        s.push_back(to_string(nums[i]));
    sort(s.begin(), s.end(), mycomp);
    for(int i = 0; i < s.size(); ++i){
        res += s[i];
    }
    if(res.length() > 1 && res[0] == '0') return "0";
    return res;
}
};
