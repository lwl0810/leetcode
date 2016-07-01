//https://leetcode.com/problems/water-and-jug-problem/

class Solution {
public:
// let a and b be nonzero integers and let d be their greatest common divisor. Then there exist integers x and y such that ax+by=d
// In addition, the greatest common divisor d is the smallest positive integer that can be written as ax + by
// every integer of the form ax + by is a multiple of the greatest common divisor d.
bool canMeasureWater(int x, int y, int z) {
    //limit brought by the statement that water is finallly in one or both buckets
    if(x + y < z) return false;
    //case x or y is zero
    if( x == z || y == z || x + y == z ) return true;

    //get gcd, then we can use the property of Bézout's identity
    return z % gcd(x, y) == 0;
}

int gcd(int a, int b){
    while(b != 0 ){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
};
