//http://www.cnblogs.com/jcliBlogger/p/4807033.html
/*
Zigzag Iterator
Given two 1d vectors, implement an iterator to return their elements alternately.
For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6] 
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		vecIdx = 0;
		vecNum = 2;
		vec.push_back(v1);
		vec.push_back(v2);
		for(int i = 0; i < vecNum; ++i){
			cur.push_back(vec[i].begin());
			end.push_back(vec[i].end());
		}
    }

    int next() {
    	int res = 0;
		res = *cur[vecIdx]++;
		vecIdx = (vecIdx + 1) % vecNum;
		return res;
    }

    bool hasNext() {
    	int cnt = 0;
    	while(cnt < vecNum && cur[vecIdx] == end[vecIdx]){
    		cnt++;
    		vecIdx = (vecIdx + 1) % vecNum;
    	}
    	if(cnt == vecNum) return false;
    	return true;
    }
private:
	vector<vector<int>> vec;
	vector<vector<int>::iterator> cur, end;
	int vecIdx, vecNum;
};
