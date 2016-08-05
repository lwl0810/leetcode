//http://www.cnblogs.com/EdwardLiu/p/5084577.html
/*
Smallest Rectangle Enclosing Black Pixels
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
The black pixels are connected, i.e., there is only one black region. 
Pixels are connected horizontally and vertically. 
Given the location (x, y) of one of the black pixels, 
return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
For example, given the following image:
[
 "0010",
 "0110",
 "0100"
]
and x = 0, y = 2,
Return 6.
*/
class Solution {
bool findBlack(vector<vector<char>>& image, int m, bool isrow){
	int row=image.size(), col=image[0].size();
	if(isrow){
		for(int i=0; i<col; i++){
			if(image[m][i]=='1')return true;
		}
	}else{
		for(int i=0; i<row; i++){
			if(image[i][m]=='1')return true;
		}
	}
	return false;
}

int searchLeft(vector<vector<char>>& image, int y){
	int l=0, r=y, m;
	while(l<=r){
		m=(l+r)/2;
		if(findBlack(image, m, false))r=m-1;
		else l=m+1;
	}
	return l;
}

int searchRight(vector<vector<char>>& image, int y){
	int l=y, r=image[0].size()-1, m;
	while(l<=r){
		m=(l+r)/2;
		if(findBlack(image, m, false))l=m+1;
		else r=m-1;
	}
	return r;
}

int searchTop(vector<vector<char>> &image, int x){
	int l=0, r=x, m;
	while(l<=r){
		m=(l+r)/2;
		if(findBlack(image, m, true))r=m-1;
		else l=m+1;
	}
	return l;
}

int searchBottom(vector<vector<char>>& image, int x){
	int l=x, r=image.size()-1, m;
	while(l<=r){
		m=(l+r)/2;
		if(findBlack(image, m, true))l=m+1;
		else r=m-1;
	}
	return r;
}


int minArea(vector<vector<char>>& image, int x, int y){
	int row=image.size();
	if(row==0)return 0;
	int col=image[0].size();
	int left=searchLeft(image, y);
	int right=searchRight(image, y);
	int top=searchTop(image, x);
	int bottom=searchBottom(image, x);
	return (right-left+1)*(bottom-top+1);
}
};
