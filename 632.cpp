class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        vector<int> ind(nums.size());
        int maxn=-100000;
        for(int i=0;i<nums.size();i++){
            ind[i]=0;
            q.push(make_pair(i,nums[i][0]));
            if(nums[i][0]>maxn) maxn=nums[i][0];
        }
        int minn=q.top().second;
        vector<int> ans={minn,maxn};
        while(q.size()){
            auto p=q.top();
            q.pop();
            minn=q.top().second;
            if(ind[p.first]<nums[p.first].size()-1){
                while(nums[p.first][ind[p.first]]==p.second && ind[p.first]<nums[p.first].size())
                    ind[p.first]++;
                if(ind[p.first]==nums[p.first].size()){
                    return ans;
                }
                q.push(make_pair(p.first,nums[p.first][ind[p.first]]));
                if(nums[p.first][ind[p.first]]>maxn) maxn=nums[p.first][ind[p.first]];
                if(nums[p.first][ind[p.first]]<minn) minn=nums[p.first][ind[p.first]];
            }else{
                break;
            }
            if(maxn-minn<ans[1]-ans[0]){
                ans={minn,maxn};
            }
        }
        return ans;
    }
};
