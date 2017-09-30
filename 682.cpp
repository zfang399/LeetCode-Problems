class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int prev=0;
        for(int i=0;i<ops.size();i++){
            if(ops[i].compare("C")==0){
                s.pop();
                if(s.size()){
                    int tmp=s.top();
                    s.pop();
                    if(s.size()) prev=s.top();
                    s.push(tmp);
                }
            }else if(ops[i].compare("D")==0){
                if(s.size()){
                    prev=s.top();
                    s.push(2*prev);
                }
            }else if(ops[i].compare("+")==0){
                int tmp=s.top();
                s.push(tmp+prev);
                prev=tmp;
            }else{
                if(s.size()) prev=s.top();
                s.push(stoi(ops[i]));
            }
        }
        int ans=0;
        while(s.size()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};
