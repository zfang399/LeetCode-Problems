class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool block=false;
        string tmp;
        for(int i=0;i<source.size();i++){
            for(int j=0;j<source[i].size();){
                if(!block){
                    if(j+1==source[i].size()){
                        tmp+=source[i][j];
                        j++;
                    }else {
                        string tt=source[i].substr(j,2);
                        if(tt.compare("/*")==0){
                            block=true;
                            j+=2;
                        }else if(tt.compare("//")==0){
                            break;
                        }else{
                            tmp+=source[i][j];
                            j++;
                        }
                    }
                }else{
                    if(j+1==source[i].size()){
                        j++;
                    }
                    else{
                        string tt=source[i].substr(j,2);
                        if (tt.compare("*/")==0){
                            block=0;
                            j+=2;
                        }else{
                            j++;
                        }
                    }
                }
            }
            //cout<<tmp<<endl;
            if(tmp.length() && !block){
                ans.push_back(tmp);
                tmp="";
            }
        }
        return ans;
    }
};
