//https://segmentfault.com/a/1190000003794736
/*
3Sum Smaller
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that 
satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Follow up: Could you solve it in O(n2) runtime?
*/

class Solution{
public:
//time O(n^2), space O(1)
int threeSumSmaller(vector<int> nums, int target){
	int sz = nums.size();
	int cnt = 0;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < sz-2; ++i){
		int low = i+1, high = sz-1;
		while(low < high){
			int sum = nums[i] + nums[low] + nums[high];
			if(sum >= target) --high;
			else{
				++low; 
				//sum from (i, low, low+1) to (i, low, high) are all smaller than target 
				cnt += high - low;
			}
			
		}	
	}
	return cnt;
}
};
