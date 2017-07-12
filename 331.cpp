class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> h;
        string t;
        for(int i=0;i<preorder.size();){
            if(preorder[i]==','){
                h.push_back(t);
                t.erase(t.begin(),t.end());
                preorder.erase(preorder.begin()+i,preorder.begin()+i+1);
            }else{
                t+=preorder[i];
                i++;
            }
        }
        h.push_back(t);
        int o=look(h,0);
        if(o==h.size()) return true;
        return false;
    }
    int look(vector<string>& h, int x){
        //cout<<x<<" "<<h[x]<<endl;
        if(x>=h.size()) return x+1;
        if(h[x][0]-'#'==0) return x+1;
        int k=look(h,x+1);
        //if(k>=h.size()) return k+1;
        return look(h,k);
    }
};
