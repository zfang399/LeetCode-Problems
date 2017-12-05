class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int maxl=-1,front=0;
        int index[150],i;
        memset(index,-1,sizeof(index));
        for(i=0;i<s.length();i++){
            if(index[s[i]]!=-1){
                if(i-front>maxl) maxl=i-front;
                if(front<index[s[i]]+1) front=index[s[i]]+1;
            }
            index[s[i]]=i;
        }
        if(i-front>maxl) maxl=i-front;
        return maxl;
    }
};
