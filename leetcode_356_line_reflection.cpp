//http://www.cnblogs.com/grandyang/p/5579271.html
//Line Reflection
//Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given set of points.
//
//Example 1:
//Given points = [[1,1],[-1,1]], return true.
//
//Example 2:
//Given points = [[1,1],[-1,-1]], return false.
//
//Follow up:
//Could you do better than O(n2)?
//
//Hint:
//
//Find the smallest and largest x-value for all points.
//If there is a line then it should be at y = (minX + maxX) / 2.
//For each point, make sure that it has a reflected point in the opposite side.

//time O(n), space O(n)
bool isReflected(vector<pair<int, int>>& points){
	int minx = INT_MAX, maxx = INT_MIN, mirror = 0;
	unordered_map<int, unordered_set<int>> um;
	for(int i = 0; i < points.size(); ++i){
		minx = min(minx, points[i].first);
		maxx = max(maxx, points[i].first);
		um[points[i].first].insert(points[i].second);
	}
	mirror = (minx + maxx) / 2;
	for(int i = 0; i < points.size(); ++i){
		int reflect = 2 * mirror - points[i].first;
		if(!um.count(reflect) || !um[reflect].count(points[i].second))
			return false;
	}
	return true;
}
