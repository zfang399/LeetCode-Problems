class Solution {
public:
    int magicalString(int n) {
        vector <int> s;
        int ans=0;
        s.push_back(1);
        s.push_back(2);
        s.push_back(2);
        int f=2;
        while(s.size()<n){
            int x=s[f];
            if(f%2==0){
                while(x>0){
                    s.push_back(1);
                    x--;
                }
            }else{
                while(x>0){
                    s.push_back(2);
                    x--;
                }
            }
            f++;
        }
        f=0;
        while(f<n){
            if(s[f]==1) ans++;
            f++;
        }
        return ans;
    }
};
