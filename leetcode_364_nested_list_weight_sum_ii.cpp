//http://www.cnblogs.com/grandyang/p/5615583.html

//Nested List Weight Sum II
//Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
//
//Example 1:
//Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
//
//Example 2:
//Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17) 
//
void layerSum(NestedInteger& ni, int layer, vector<int>& layers){
	if(layers.size()-1 < layer){
		layers.push_back(0);
	}
	if(ni.isInteger()){
		layers[layer] += ni.getInteger();
	}else{
		vector<NestedInteger> &v = ni.getList();
		for(int i = 0; i < v.size(); ++i){
			layerSum(v[i], layer+1, layers);
		}
	}
}

int depthSumInverse(vector<NestedInteger>& nestedList){
	vector<int> layers;
	for(int i = 0; i < nestedList.size(); ++i){
		layerSum(nestedList[i], 0, layers);
	}
	int sz = layers.size(), layer = sz, res = 0;
	for(int i = 0; i < sz; ++i){
		res += layers[i] * layer;
		layer--;
	}
	return res;
}

//两个变量unweighted和weighted，非权重和跟权重和，初始化均为0，
//然后如果nestedList不为空开始循环，先声明一个空数组nextLevel，遍历nestedList中的元素，
//如果是数字，则非权重和加上这个数字，如果是数组，就加入nextLevel，
//这样遍历完成后，第一层的数字和保存在非权重和unweighted中了，其余元素都存入了nextLevel中，
//此时我们将unweighted加到weighted中，将nextLevel赋给nestedList，
//这样再进入下一层计算，由于上一层的值还在unweighted中，所以第二层计算完将unweighted加入weighted中时，相当于第一层的数字和被加了两次
int depthSumInverse1(vector<NestedInteger>& nestedList) {
	int unweighted = 0, weighted = 0;
	while (!nestedList.empty()) {
		vector<NestedInteger> nextLevel;
		for(int i = 0; i < nestedList.size(); ++i){
			if(nestedList[i].isInteger()) {
				unweighted += nestedList[i].getInteger();
			} else {
				nextLevel.insert(nextLevel.end(), nestedList[i].getList().begin(), nestedList[i].getList().end());
			}
		}
		weighted += unweighted;
		nestedList = nextLevel;
	}
	return weighted;
}
