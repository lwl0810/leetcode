//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
//time O(nlogk) space O(k)
// int findKthLargest(vector<int>& nums, int k) {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for(int i = 0; i < nums.size(); ++i){
//         pq.push(nums[i]);
//         if(pq.size() > k) pq.pop();
//     }
//     return pq.top();
// }

//divide and conquer
int partition(vector<int>& nums, int start, int length, int k){
    int pivot = nums[start];
    int i = start+1, j = start+length-1;
    while(i <= j){
        if(nums[i] >= pivot){
            i++;
        }else{
            swap(nums[i], nums[j]);
            j--;
        }
    }
    int newlen = j - start;
    if(newlen == k-1) return pivot;
    if(newlen >= k) return partition(nums, start+1, newlen, k);
    return partition(nums, i, length-newlen-1, k-newlen-1);
    
//     srand(time(NULL));
//     int pivot = nums[start+rand()%length];
//     int i = start, j = start;
// 	while(i < start+length){
// 		if(nums[i] >= pivot){
// 			swap(nums[i], nums[j]);
// 			j++;
// 		}
// 		i++;
// 	}
//     int newlen = j-start;
//     if(newlen == k) return pivot;
//     if(newlen > k) return partition(nums, start, newlen, k);
//     return partition(nums, j, length-newlen, k-newlen);
}

int findKthLargest(vector<int>& nums, int k){
    return partition(nums, 0, nums.size(), k);
}
};
