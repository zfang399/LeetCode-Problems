class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        stack<string> s;
        stack<int> left;
        stack<int> right;
        s.push("(");
        left.push(1);
        right.push(0);
        while(!s.empty()){
            string x=s.top();
            s.pop();
            int l=left.top();
            left.pop();
            int r=right.top();
            right.pop();
            if(l<r) continue;
            if(l==r && l==n){
                ans.push_back(x);
                continue;
            }else if(l==r){
                s.push(x+"(");
                left.push(l+1);
                right.push(r);
            }else if(l==n){
                while(r<l){
                    r++;
                    x+=")";
                }
                ans.push_back(x);
                continue;
            }else{
                s.push(x+"(");
                left.push(l+1);
                right.push(r);

                s.push(x+")");
                left.push(l);
                right.push(r+1);
            }
        }
        return ans;
    }
};
