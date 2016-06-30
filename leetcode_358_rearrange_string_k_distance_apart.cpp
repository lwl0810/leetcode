//http://www.cnblogs.com/grandyang/p/5586009.html
//Rearrange String k Distance Apart
// 
//Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
//All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
//
//Example 1:
//str = "aabbcc", k = 3
//Result: "abcabc"
//The same letters are at least distance 3 from each other.

//Example 2:
//str = "aaabc", k = 3 
//Answer: ""
//It is not possible to rearrange the string.

//Example 3:
//str = "aaadbbcc", k = 2
//Answer: "abacabcd"
//Another possible answer is: "abcabcda"
//The same letters are at least distance 2 from each other.

//time O(n), space O(n)
string rearrangeString(string str, int k){
	string res = "";
	CharItem* um[26] = {NULL};
	for(int i = 0; i < str.length(); ++i){
		if(um[str[i]-'a']) um[str[i]-'a']->num++;
		else um[str[i]-'a'] = new CharItem(str[i], 1);
	}
	priority_queue<CharItem*, vector<CharItem*>, mycomp> pq;
	queue<CharItem*> cooling;
	for(int i = 0; i < 26; ++i){
		if(um[i]) pq.push(um[i]);
	}
	while(!pq.empty() || !cooling.empty()){
		while(!cooling.empty()){
			int preIndex = cooling.front()->preIdx;
			if(res.length() - preIndex >= k){
				pq.push(cooling.front());
				cooling.pop();
			}else break;
		}
		if(pq.empty()) return "";
		CharItem* cur = pq.top();
		pq.pop();
		res += cur->ch;
		cur->preIdx = res.length()-1;
		cur->num--;
		if(cur->num != 0) cooling.push(cur);
	}
	return res;
}
