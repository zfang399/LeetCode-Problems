class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i=0;i<12;i++){
            int n=num,t=i;
            while(t>0){
                if(t%2!=0){
                    n--;
                }
                t/=2;
            }
            if(n<0) continue;
            for(int j=0;j<60;j++){
                int m=n,t=j;
                while(t>0){
                    if(t%2!=0){
                        m--;
                    }
                    t/=2;
                }
                if(m==0){
                    if(j<10){
                        ans.push_back(to_string(i)+":0"+to_string(j));
                    }else{
                        ans.push_back(to_string(i)+":"+to_string(j));
                    }
                }
            }
        }
        return ans;
    }
};
