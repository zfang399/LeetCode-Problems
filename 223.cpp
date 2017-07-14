class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int cl=max(A,E);
        int cr=max(min(C,G),cl);
        int cd=max(B,F);
        int cu=max(min(D,H),cd);
        return (C-A)*(D-B)-(cr-cl)*(cu-cd)+(G-E)*(H-F);
    }
};
