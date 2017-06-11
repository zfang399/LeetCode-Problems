class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(nums1.size()<nums2.size()){
            for(int i=0;i<nums1.size();i++){
                std::vector<int>::iterator p=find(nums2.begin(),nums2.end(),nums1[i]);
                if(p!=nums2.end()){
                    ans.push_back(nums1[i]);
                    nums2.erase(p);
                }
            }
        }else{
            for(int i=0;i<nums2.size();i++){
                std::vector<int>::iterator p=find(nums1.begin(),nums1.end(),nums2[i]);
                if(p!=nums1.end()){
                    ans.push_back(nums2[i]);
                    nums1.erase(p);
                }
            }
        }
        return ans;
    }
};
