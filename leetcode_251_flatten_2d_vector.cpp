//http://www.cnblogs.com/jcliBlogger/p/4704781.html
/*
Flatten 2D Vector
Implement an iterator to flatten a 2d vector.
For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 2, 3, 4, 5, 6].
*/

class Vector2D{
public:
Vector2D(vector<vector<int>>& vec2d){
	vec = vec2d;
	it = vec.begin();
	pos = 0;
}

int next(){
	return (*it)[pos++];
}

bool hasNext(){
	while(it != vec.end() && pos == (*it).size()) {
		++it;
		pos = 0;
	}
	return it != vec.end();
}

private:
	vector<vector<int>> vec;
	vector<vector<int>>::iterator it;
	int pos;
};
