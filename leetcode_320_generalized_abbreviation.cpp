//http://blog.csdn.net/hjf0416/article/details/50461816
/*
Generalized Abbreviation
 Write a function to generate the generalized abbreviations of a word.
Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution{
public:
void genAbbr(vector<string>& res, string word, int idx) {
	for(int j = idx; j < word.length(); ++j){
		for(int i = 1; i + j <= word.length(); ++i){
			string newword = word.substr(0, j) + to_string(i) + word.substr(j+i);
			res.push_back(newword);
			//warning: since the length of newword maybe different to word, the idx is j+i+1-(i-1)
			genAbbr(res, newword, j+2);
		}
	}
}

vector<string> Q320::generateAbbreviations(string word) {
	vector<string> res;
	res.push_back(word);
	genAbbr(res, word, 0);
	return res;
}
};
