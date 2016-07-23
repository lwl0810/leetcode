//https://segmentfault.com/a/1190000003790309

/*
Missing Ranges
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
//time O(n), space O(n)
//add lower-1 and upper+1 at the beginning and ending of nums to simplify code
vector<string> findMissingRanges(vector<int> nums, int lower, int upper) {
	vector<string> res;
	nums.push_back(upper+1);
	int pre = lower-1, sz = nums.size();
	for(int i = 0; i < sz; ++i){
		if(nums[i] - pre == 2)	res.push_back(to_string(pre+1));
		if(nums[i] - pre > 2)	res.push_back(to_string(pre+1) + "->" + to_string(nums[i]-1));
		pre = nums[i];
	}
	return res;
}
};
