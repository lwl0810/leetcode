//
//Sort Transformed Array 变换数组排序
//
//Given a sorted array of integers nums and integer values a, b and c. 
//Apply a function of the form f(x) = ax^2 + bx + c to each element x in the array.
//The returned array must be in sorted order.
//Expected time complexity: O(n)
//
//Example:
//nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
//Result: [3, 9, 15, 33]
//
//nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
//Result: [-23, -5, 1, 7]

//time O(n)
int calculate(int x, int a, int b, int c){
	return x*x*a+x*b+c;
}

vector<int> Q360::sortTransformedArray(vector<int>& nums, int a, int b, int c){
	int sz = nums.size();
	vector<int> res(sz, 0);
	int i = 0, j = sz-1, k = a >= 0 ? sz-1 : 0;
	while(i <= j){
		int ci = calculate(nums[i],a,b,c), cj = calculate(nums[j],a,b,c);
		if(a >= 0){
			if(ci > cj){ res[k] = ci; i++;} 
			else{ res[k] = cj; j--; }
			k--;
		}else{
			if(ci < cj){ res[k] = ci; i++; }
			else{ res[k] = cj; j--; }
			k++;
		}
	}
	return res;
}
