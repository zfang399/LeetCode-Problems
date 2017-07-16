class Solution {
public:
    int calculate(string s) {
        int i=0;
        long long cur=0,ans=0;
        vector<int> nums;
        vector<char> ops;
        for(int i=0;i<s.size();){
            while(s[i]==' ') i++;
            if(i>=s.size()) break;
            if(s[i]-'0'>=0 && s[i]-'0'<=9){
                int x=0;
                while(s[i]-'0'>=0 && s[i]-'0'<=9){
                    x=x*10+s[i]-'0';
                    i++;
                }
                nums.push_back(x);
            }else{
                ops.push_back(s[i]);
                i++;
            }
        }
        cur=nums[0];
        bool add=false;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=='+' || ops[i]=='-'){
                ans+=cur;
                if(ops[i]=='+') cur=nums[i+1];
                else cur=-nums[i+1];
            }else{
                if(ops[i]=='*'){
                    cur*=nums[i+1];
                }else{
                    cur/=nums[i+1];
                }
            }
        }
        ans+=cur;
        return ans;
    }
};
