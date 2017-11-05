class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans=0;
        if(A.size()<3) return 0;
        vector<int> v(A.size()+1,0);
        v[3]=1;
        for(int i=4;i<=A.size();i++){
            v[i]=v[i-1]+i-2;
        }
        int diff=A[1]-A[0];
        int count=2;
        for(int i=2;i<A.size();i++){
            if((A[i]-A[i-1])==diff){
                count++;
            }else{
                ans+=v[count];
                diff=A[i]-A[i-1];
                count=2;
            }
        }
        ans+=v[count];
        return ans;
    }
};
