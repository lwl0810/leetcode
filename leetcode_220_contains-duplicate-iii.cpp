//https://leetcode.com/problems/contains-duplicate-iii/

bool comptr(int *a, int *b){
	return *a<*b;
}

class Solution {
public:
//faster than bucket solution based on the given test case
//time O(n^2)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
	int size=nums.size();
	vector<int*> numptrs;
	for(int i=0; i<size; ++i){
		numptrs.push_back(&nums[i]);
	}
	sort(numptrs.begin(), numptrs.end(), comptr);
	if(0==k) return false;
	for(int i=0; i<size; ++i){
		for(int j=i+1; j<size; ++j){
			if(*numptrs[j] > *numptrs[i]+t) //*numptrs[j] - *numptrs[i] > t may cause overflow
				break;
            if(abs(numptrs[j]-numptrs[i]) <= k) 
				return true;
		}
	}
	return false;
}

//tiem O(n)
// bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//     int sz = nums.size();
//     if(sz < 2 || k < 1 || t < 0) return false;
//     unordered_map<long, long> um;
//     for(int i = 0; i < sz; ++i){
//         long tmp = (long)nums[i] - INT_MIN;
//         long bucket = tmp / ((long)t + 1);
//         if (um.find(bucket) != um.end() ||
//             um.find(bucket-1) != um.end() && tmp - um[bucket-1] <= t ||
//             um.find(bucket+1) != um.end() && um[bucket+1] - tmp <= t) return true;
//         if(um.size() >= k){
//             long lastbucket = ((long)nums[i-k] - INT_MIN) / ((long)t + 1);
//             um.erase(lastbucket);
//         }
//         um[bucket] = tmp;
//     }
//     return false;
// }
};
