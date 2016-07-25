//http://www.cnblogs.com/jcliBlogger/p/4738788.html
/*
Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.

For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Hint:
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together inedges.
*/

class Solution{
public:
bool hasCycle(vector<vector<int>>& nodes, vector<bool>& isvisited){
	stack<int> s;
	s.push(0);
	while(!s.empty()){
		int cur = s.top();
		if(isvisited[cur]) return true;
		isvisited[cur] = true;
		s.pop();
		for(int i = 0; i < nodes[cur].size(); ++i){
			if(isvisited[nodes[cur][i]]) continue;
			s.push(nodes[cur][i]);
		}
	}
	return false;
}

bool validTree(int n, vector<pair<int, int>>& edges){
	vector<vector<int>> nodes(n);
	for(int i = 0; i < edges.size(); ++i){
		nodes[edges[i].first].push_back(edges[i].second);
		nodes[edges[i].second].push_back(edges[i].first);
	}
	vector<bool> isvisited(n, false);
	if(hasCycle(nodes, isvisited)) return false;
	for(int i = 0; i < n; ++i)
		if(!isvisited[i]) return false;
	return true;
}
};
