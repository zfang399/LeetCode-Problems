class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i].length()>1) nums.push(stoi(tokens[i]));
            else if(tokens[i][0]-'0'>=0 && tokens[i][0]-'0'<=9) nums.push(stoi(tokens[i]));
            else{
                int b=nums.top();
                nums.pop();
                int a=nums.top();
                nums.pop();
                if(tokens[i]=="+"){
                    nums.push(a+b);
                }else if(tokens[i]=="-"){
                    nums.push(a-b);
                }else if(tokens[i]=="*"){
                    nums.push(a*b);
                }else{
                    nums.push(a/b);
                }
            }
        }
        return nums.top();
    }
};
