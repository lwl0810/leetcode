//https://leetcode.com/problems/power-of-two/

class Solution {
public:

bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    int num = n & (~n + 1);
    if((num & n) == n) return true;
    return false;
}

// bool isPowerOfTwo(int n) {
//     if(n <= 0) return false;
//     int num = 1;
//     for(int i = 0; i < 31; ++i){
//         if(num == n) return true;
//         num <<= 1;
//     }
//     return false;
// }
};
