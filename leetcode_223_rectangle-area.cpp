//https://leetcode.com/problems/rectangle-area/

class Solution {
public:
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = (C - A) * (D - B);
    int area2 = (G - E) * (H - F);
    //4 possible position that two rectangles have no intersection
    int intersection = (C < E || H < B || G < A || D < F)? 0: (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    return area1 + area2 - intersection;
}
};
