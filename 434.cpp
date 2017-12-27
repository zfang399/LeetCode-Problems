class Solution {
public:
    int countSegments(string s) {
        if(s=="") return 0;
        int i=0,ans=0;
        bool prev;
        if(s[i]==' '){
            prev=true;
        }else{
            prev=false;
            ans=1;
        }
        while(i<s.length()){
            if(s[i]!=' ' && prev==true){
                ans++;
                prev=false;
            }else if(s[i]==' '){
                prev=true;
            }
            i++;
        }
        return ans;
    }
}; 
