//https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
//maintain a map to store the remainder and the position of each quotient in result
string fractionToDecimal(int numerator, int denominator) {
    int sign = (numerator>0 && denominator<0 || numerator<0 && denominator>0)? -1: 1;
    long n = labs(numerator), d = labs(denominator), r = 0;
    string res = to_string(sign * (n / d));
    r = n % d;
    if(r == 0) return res;
    res += '.';
    
    unordered_map<long, int> remainders;
    string decimal = "";
    while(r != 0){
        remainders[r] = decimal.length();
        r *= 10;
        decimal += to_string(r / d);
        r %= d;
        if(remainders.find(r) != remainders.end()) break;
    }
    if(sign == -1 && res[0] != '-') res = "-" + res;
    if(r == 0){
        res += decimal;
        return res;
    }
    res += decimal.substr(0, remainders[r]) + "(" + decimal.substr(remainders[r]) + ")";
    return res;
}
};
