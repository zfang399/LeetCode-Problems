class CompareDist
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first+a.second>b.first+b.second;
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        if (nums1.empty() || nums2.empty() || k <= 0) return ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist> q;
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)
                q.push(make_pair(nums1[i],nums2[j]));
        while(k>0 && q.size()){
            k--;
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
