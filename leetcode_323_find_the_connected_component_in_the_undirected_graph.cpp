//http://www.cnblogs.com/easonliu/p/4606255.html
/*
Find the Connected Component in the Undirected Graph
Find the number connected component in the undirected graph. 
Each node in the graph contains a label and a list of its neighbors. 
(a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other 
by paths, and which is connected to no additional vertices in the supergraph.)
 
Example
Given graph:
A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E
Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
*/

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
class Solution{
public:
//Union Find solution
//Union Find solution
UndirectedGraphNode* find(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& indice, UndirectedGraphNode* id) {
	while(id != indice[id]) {
		indice[id] = indice[indice[id]];
		id = indice[id];
	}
	return id;
}

vector<vector<int>> Q323::connectedSet(vector<UndirectedGraphNode*>& nodes) {
	vector<vector<int>> res;
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> indice;
	for(int i = 0; i < nodes.size(); ++i)
		indice[nodes[i]] = nodes[i];
	for(int i = 0; i < nodes.size(); ++i) {
		vector<UndirectedGraphNode*> ns = nodes[i]->neighbors;
		for(int j = 0; j < ns.size(); ++j){
			UndirectedGraphNode* nodeId = find(indice, nodes[i]);
			UndirectedGraphNode* nsId = find(indice, ns[j]);
			if(indice[nodeId] != indice[nsId]) {
				indice[nsId] = indice[nodeId];
			}
		}
	}
	
	unordered_map<UndirectedGraphNode*, vector<int>> subsets;
	for(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it = indice.begin(); it != indice.end(); ++it) {
		//warning: the key is indice[it->second], not just it->second
		subsets[indice[it->second]].push_back(it->first->label);
	}
	for(unordered_map<UndirectedGraphNode*, vector<int>>::iterator it = subsets.begin(); it != subsets.end(); ++it) {
		res.push_back(it->second);
	}
	return res;
}

/*
//DFS solution
void dfs(vector<UndirectedGraphNode*>& nodes, unordered_set<UndirectedGraphNode*>& visit, 
		vector<int>& subset, UndirectedGraphNode* cur) {
	visit.insert(cur);
	subset.push_back(cur->label);
	vector<UndirectedGraphNode*> ns = cur->neighbors;
	for(int i = 0; i < ns.size(); ++i){
		if(visit.find(ns[i]) != visit.end()) continue;
		dfs(nodes, visit, subset, ns[i]);
	}
}

vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
	vector<vector<int>> res;
	unordered_set<UndirectedGraphNode*>& visit;
	for(int i = 0; i < nodes.size(); ++i){
		if(visit.find(nodes[i]) == visit.end()){
			vector<int> subset;
			dfs(nodes, visit, subset, nodes[i]);
			res.push_back(subset);
		}
	}
	return res;
}


//BFS solution
vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
	vector<vector<int>> res;
	unordered_set<UndirectedGraphNode*> visit;
	for(int i = 0; i < nodes.size(); ++i) {
		if(visit.find(nodes[i]) != visit.end()) continue;
		vector<int> subset;
		queue<UndirectedGraphNode*> q;
		q.push(nodes[i]);
		visit.insert(nodes[i]);
		while(!q.empty()){
			UndirectedGraphNode *cur = q.front();
			q.pop();
			subset.push_back(cur->label);
			vector<UndirectedGraphNode*> ns = cur->neighbors;
			for(int j = 0; j < ns.size(); ++j){
				if(visit.find(ns[j]) != visit.end()) continue;
				q.push(ns[j]);
				visit.insert(ns[j]);
			}
		}
		res.push_back(subset);
	}
	return res;
}
*/
};
