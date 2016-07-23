//http://buttercola.blogspot.com/2015/08/leetcode-strobogrammatic-number.html
/*
Strobogrammatic Number
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

class Solution{
public:
bool isStrobogrammatic(string num){
 	int len = num.length();
 	for(int i = 0; i < len/2; ++i){
 		if(num[i] != '0' && num[i] != '1' && num[i] != '6' && num[i] != '8' && num[i] != '9') return false;
 		if(num[i] == '0' && num[len-1-i] == '0') continue;
 		if(num[i] == '1' && num[len-1-i] == '1') continue;
 		if(num[i] == '6' && num[len-1-i] == '9') continue;
 		if(num[i] == '8' && num[len-1-i] == '8') continue;
 		if(num[i] == '9' && num[len-1-i] == '6') continue;
 		return false;
 	}
 	if(len % 2 == 0) return true;
 	if(num[len/2] == '0' || num[len/2] == '1' || num[len/2] == '8') return true;
 	return false;
 	
	// unordered_map<char, char> um;
	// um['0'] = '0'; um['1'] = '1'; um['6'] = '9'; um['8'] = '8'; um['9'] = '6';
	// int l = 0, r = num.length()-1;
	// while(l <= r){
	// 	if(um.find(num[l]) == um.end() || um[num[l]] != num[r])
	// 		return false;
	// }
	// return true;
}
};
