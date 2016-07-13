//https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
int guessNumber(int n) {
    int s = 1, e = n, num = 0, r = 0;
    while(s <= e){
        num = s + (e - s) / 2;
        r = guess(num);
        if(r == 0) break;
        else if(r == -1) e = num - 1;
        else s = num + 1;
    }
    return num;
}
};
