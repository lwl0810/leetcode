//https://leetcode.com/problems/count-and-say/
class Solution {
public:
string countAndSay(int n) {
    string res = "1";        
    char cur = 0;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        string tmp = "";
        for (int j = 0; j < res.length(); j++) {
            if(j == 0) {
                cur = res[j];
                cnt = 1;
            } else {
                if(res[j] != res[j-1]) {
                    tmp += to_string(cnt) + cur;
                    cnt = 1;
                    cur = res[j];
                } else {
                    cnt++;
                }
            }
        }
        tmp += to_string(cnt) + cur;
        res = tmp;
    }
    return res;
}
};
