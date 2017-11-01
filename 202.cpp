class Solution {
public:
    unordered_map<int,bool> visited;
    bool isHappy(int n) {
        cout<<n<<endl;
        if(visited[n]) return false;
        visited[n]=true;
        int next=0;
        while(n>=10){
            next+=(n%10)*(n%10);
            n/=10;
        }
        next+=n*n;
        if(next==1) return true;
        return isHappy(next); 
    }
};
