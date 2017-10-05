class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i=0;i<A.length();i++){
            if(A[i]==B[0]){
                if(A.length()-i>=B.length()){
                    if(A.substr(i,B.length()).compare(B)==0) return 1;
                }else{
                    if(B.substr(0,A.length()-i).compare(A.substr(i))==0){
                        string t=B.substr(A.length()-i);
                        int ret=1;
                        while(t.substr(0,A.length()).compare(A)==0 && t.length()>=A.length()){
                            ret++;
                            t=t.substr(A.length());
                        }
                        if(!t.length()) return ret;
                        if(A.substr(0,t.length()).compare(t)==0){
                            ret++;
                            return ret;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
