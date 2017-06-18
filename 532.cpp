class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        unordered_map <int,int> exist;
        unordered_map <int,bool> visited;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            exist[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(k==0){
                if(exist[nums[i]]>1 && visited[nums[i]]!=true){
                    ans++;
                    visited[nums[i]]=true;
                }
            }else{
                if(exist[nums[i]-k] && visited[nums[i]]!=true){
                    ans++;
                    visited[nums[i]]=true;
                }
            }
        }
        return ans;
    }
};
