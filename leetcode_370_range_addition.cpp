//http://blog.csdn.net/jmspan/article/details/51787011

//Assume you have an array of length n initialized with all 0's and are given k update operations.
//Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
//Return the modified array after all k operations were executed.
//Example:
//Given:
//    length = 5,
//    updates = [
//        [1,  3,  2],
//        [2,  4,  3],
//        [0,  2, -2]
//    ]
//Output:
//    [-2, 0, 3, 5, 3]
//Explanation:
//Initial state:
//[ 0, 0, 0, 0, 0 ]
//
//After applying operation [1, 3, 2]:
//[ 0, 2, 2, 2, 0 ]
//
//After applying operation [2, 4, 3]:
//[ 0, 2, 5, 5, 3 ]
//
//After applying operation [0, 2, -2]:
//[-2, 0, 3, 5, 3 ]
//Hint:
//Thinking of using advanced data structures? You are thinking it too complicated.
//For each update operation, do you really need to update all elements between i and j?
//Update only the first and end element is sufficient.
//The optimal time complexity is O(k + n) and uses O(1) extra space.

//time O(k+n), space O(1)
//for update[i]: [s, e, val]
//plus the res[s](s is the start of interval) by val
//minus the res[e+1](e is the end of interval) by val
vector<int> Q370::getModifiedArray(int length, vector<vector<int>>& updates){
	int sz = updates.size();
	vector<int> res(length, 0);
	for(int i = 0; i < sz; ++i){
		int s = updates[i][0];
		int e = updates[i][1] + 1;
		int val = updates[i][2];
		res[s] += val;
		if(e < length) res[e] -= val;
	}
	int val = 0;
	for(int i = 0; i < length; ++i){
		val += res[i];
		res[i] = val;
	}
	return res;
}
