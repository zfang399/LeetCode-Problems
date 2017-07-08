class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int> m;
        m[(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1])]++;
        m[(p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1])]++;
        m[(p1[0]-p4[0])*(p1[0]-p4[0])+(p1[1]-p4[1])*(p1[1]-p4[1])]++;
        m[(p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1])]++;
        m[(p2[0]-p4[0])*(p2[0]-p4[0])+(p2[1]-p4[1])*(p2[1]-p4[1])]++;
        m[(p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1])]++;
        return !m.count(0)&&m.size()==2;
    }
};
