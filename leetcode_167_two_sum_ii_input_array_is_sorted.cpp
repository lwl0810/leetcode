//http://blog.csdn.net/xudli/article/details/42290269

/*
Two Sum II - Input array is sorted Total Accepted: 441 Total Submissions: 1017
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
//time O(n), space O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> res;
	int start = 0, end = numbers.size()-1;
	long sum = 0;
	while(start < end){
		sum = numbers[start] + numbers[end];
		if(sum == target) break;
		else if(sum > target) --end;
		else ++start;
	}
	res.push_back(start+1);
	res.push_back(end+1);
	return res;
}
};
