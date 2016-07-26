//http://www.cnblogs.com/jcliBlogger/p/4758761.html
/*
//There is a new alien language which uses the latin alphabet. 
//However, the order among letters are unknown to you. You receive a list of words from the dictionary, 
//wherewords are sorted lexicographically by the rules of this new language. 
//Derive the order of letters in this language.
//For example,
//Given the following words in dictionary,
//
//[
//  "wrt",
//  "wrf",
//  "er",
//  "ett",
//  "rftt"
//]
//The correct order is: "wertf".
//
//Note:
//You may assume all letters are in lowercase.
//If the order is invalid, return an empty string.
//There may be multiple valid order of letters, return any one of them is fine.
*/

class Solution{
public:
void buildGraph(vector<vector<bool>>& graph, vector<int>& preCnt, vector<string>& words){
	for(int i = 1; i < words.size(); ++i){
		int len1 = words[i-1].length(), len2 = words[i].length();
		for(int j = 0; j < max(len1, len2); ++j){
			if(j < len1 && preCnt[words[i-1][j]-'a'] == -1) preCnt[words[i-1][j]-'a'] = 0;
			if(j < len2 && preCnt[words[i][j]-'a'] == -1) preCnt[words[i][j]-'a'] = 0;
			if(j >= len1 || j >= len2 || words[i-1][j] == words[i][j]) continue;
			graph[words[i][j]-'a'][words[i-1][j]-'a'] = true;
			preCnt[words[i][j]-'a']++;
			break;
		}
	}
}

string alienOrder(vector<string>& words){
	vector<vector<bool>> graph(26, vector<bool>(26, false));
	vector<int> preCnt(26, -1);
	string res = "";
	buildGraph(graph, preCnt, words);
	//topological sort
	queue<int> noPre;
	for(int i = 0; i < 26; ++i)
		if(preCnt[i] == 0) noPre.push(i);
	if(noPre.empty()) return res;
	while(!noPre.empty()){
		int cur = noPre.front();
		noPre.pop();
		res += char(cur+'a');
		for(int i = 0; i < 26; ++i){
			if(graph[i][cur]){
				graph[i][cur] = false;
				preCnt[i]--;
				if(preCnt[i] == 0) noPre.push(i);
			}
		}
	}
	return res;
}
};

