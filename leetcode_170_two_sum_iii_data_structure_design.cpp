//http://blog.csdn.net/pointbreak1/article/details/48797961
/*
Design and implement a TwoSum class. It should support the following operations:add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:
//Add the number to an internal data structure.
void add(int number) {
	um[number]++;
}

//Find if there exists any pair of numbers which sum is equal to the value.
//time O(n)
bool find(int value) {
	for(unordered_map<int,int>::iterator it = um.begin(); it != um.end(); it++){
		int target = value - it->first;
		if(target != it->first && um.find(target) != um.end() || target == it->first && it->second > 1)
			return true;
	}
	return false;	
}

private:
    unordered_map<int, int> um;
};
