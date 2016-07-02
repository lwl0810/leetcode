//https://leetcode.com/problems/integer-to-roman/

class Solution {
public:

//I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
string intToRoman(int num) {
    string res = "";
    while(num >= 1000){
        num -= 1000;
        res += "M";
    }
    if(num >= 900){
        num -= 900;
        res += "CM";
    }
    if(num >= 500 && num < 900){
        num -= 500;
        res += "D";
        while(num >= 100) {
            res += "C";
            num -= 100;
        }
    }
    if(num >= 400){
        num -= 400;
        res += "CD";
    }
    
    while(num >= 100){
        num -= 100;
        res += "C";
    }
    if(num >= 90){
        num -= 90;
        res += "XC";
    }
    if(num >= 50 && num < 90){
        num -= 50;
        res += "L";
        while(num >= 10){
            res += "X";
            num -= 10;
        }
    }
    if(num >= 40){
        num -= 40;
        res += "XL";
    }
    
    while(num >= 10){
        num -= 10;
        res += "X";
    }
    if(num >= 9){
        num -= 9;
        res += "IX";
    }
    if(num >= 5 && num < 9){
        num -= 5;
        res += "V";
        while(num >= 1){
            res += "I";
            num -= 1;
        }
    }
    if(num >= 4){
        num -= 4;
        res += "IV";
    }
    while(num >= 1){
        num -= 1;
        res += "I";
    }
    return res;
}
};
