//https://leetcode.com/problems/patching-array/

class Solution {
public:
//greedy: for i from 1 to n, if sum>=i, no need to add more; if sum<i and num[j]>i, need to add one
int minPatches(vector<int>& nums, int n) {
    int sz = nums.size();
	//n may be INT_MAX
    long i = 1, sum = 0;
    int j = 0, cnt = 0;
    while(i <= n){
        while(sum < i){
			if(j < sz && nums[j] <= i){
				sum += nums[j++];
			}else{
			    cnt++;
				sum += i;
			}
		}
		i = sum+1;
    }
    return cnt;
}
};
