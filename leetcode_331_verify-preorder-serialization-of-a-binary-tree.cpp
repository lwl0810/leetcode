//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:
//recursion solution
/*
bool validHelp(string& str){
	if(str == "") return false;
	int pos = str.find_first_of(',');//+1 skip ','
	string cur = str.substr(0, pos);
	if(pos == -1) str = "";
	else str = str.substr(pos+1);
	if(cur == "#") return true;
	
	if(!validHelp(str) || !validHelp(str)) return false;
	return true;
}

bool isValidSerialization(string preorder){
	bool b = validHelp(preorder);
	if(!b) return false;
	else{
		if(preorder.length() != 0) return false;
		else return true;
	}
}
*/

//iteration solution
bool isValidSerialization(string preorder){
	queue<string> nodes;
	stringstream ss(preorder);
    string node;
    while(getline(ss, node, ',')) nodes.push(node);

	if(nodes.size() == 0) return false;
	int stackcnt = 0; //work as stack
	while(stackcnt >= 0){ //stack is invalid
		while(!nodes.empty() && nodes.front() != "#"){
			stackcnt++;
			nodes.pop();
		}
		if(!nodes.empty()) nodes.pop();
		if(nodes.empty()) break;
		stackcnt--;
	}
	if(stackcnt == 0 && nodes.empty()) return true;
	return false;
}
};
