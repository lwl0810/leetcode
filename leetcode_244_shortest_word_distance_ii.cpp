//http://likesky3.iteye.com/blog/2236157
/*
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it? 
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. 

For example, 
Assume that words = ["practice", "makes", "perfect", "coding", "makes"]. 

Given word1 = “coding”, word2 = “practice”, return 3. 
Given word1 = "makes", word2 = "coding", return 1. 

Note: 
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list. 
*/

class WordDistance {
public:
WordDistance(vector<string> words){
	for(int i=0; i<words.size(); i++)
		um[words[i]].push_back(i);
}

//time O(n), space O(n)
int shortest(string word1, string word2){
	int shortest = INT_MAX, i = 0, j = 0;
	vector<int> v1 = um[word1], v2 = um[word2];
	while(i < v1.size() && j < v2.size()){
		if(i < j){
			shortest = min(shortest, v2[j] - v1[i]);
			++i;
		}else{
			shortest = min(shortest, v1[i] - v2[j]);
			++j;
		}
	}
	return shortest;
}

private:
	unordered_map<string, vector<int>> um;
};

// Your WordDistance object will be instantiated and called as such:  
// WordDistance wordDistance = new WordDistance(words);  
// wordDistance.shortest("word1", "word2");  
// wordDistance.shortest("anotherWord1", "anotherWord2");  
