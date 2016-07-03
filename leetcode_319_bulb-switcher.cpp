//https://leetcode.com/problems/bulb-switcher/

class Solution {
public:
/*
Now the purpose here is clear searching for the odd-operation numbers:

as for primes, they only have 1 and itself as their factors; so primes are even-operation numbers;
as for non-primes, normally they will have different pairs of factors like 12 whose factors are 1*12, 2*6, 3*4 - 
6 different factors, so they are also even-operation numbers;
but among non-primes, there are some special numbers which are square numbers like 9 
whose factors are 1*9, 3*3 - three different factors which means we finally got odd-operation numbers!
So that's all we need to know to hack this problem now. 
But how to get the amount of squares that are less than n, quite simple, right? 
sqrt(n) is the answer. all square numbers that is less than n will be 1, 4, 9 ... n and corresponding root will be 1, 2, 3,... sqrt(n) Get it?

Space cost O(1)
Time cost O(1)
*/
int bulbSwitch(int n){
	return (int)sqrt((double)n);
}
};
