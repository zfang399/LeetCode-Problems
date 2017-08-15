class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size(),l2=s2.size();
        if(l1+l2!=s3.size()) return false;
        vector<vector<bool>> itl(l1+1,vector<bool>(l2+1,false));
        itl[0][0]=true;
        for(int i=0;i<s3.size();i++){
            for(int j=max(0,i-l2);j<min(l1,i+1);j++){
                if(s1[j]==s3[i] && itl[j][i-j]) itl[j+1][i-j]=true;
            }
            for(int j=max(0,i-l1);j<min(l2,i+1);j++){
                if(s2[j]==s3[i] && itl[i-j][j]) itl[i-j][j+1]=true;
            }
        }
        if(itl[l1][l2]) return true;
        return false;
    }
};
