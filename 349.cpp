class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map <int,bool> a;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++) a[nums1[i]]=true;
        for(int i=0;i<nums2.size();i++){
            if(a[nums2[i]]){
                a[nums2[i]]=false;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};
