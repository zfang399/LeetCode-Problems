class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int i=0,j=0;
        int c1=0,c2=0;
        while(c1<n1){
            if(s1[i]==s2[j]){
                j++;
                if(j==s2.length()){
                    j=0;
                    c2++;
                }
            }
            i++;
            if(i==s1.length()){
                i=0;
                c1++;
            }
        }
        return c2/n2;
    }
};
