class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.size()==0){
            nums1=nums2;
            return;
        }else if(nums2.size()==0) return;
        nums1.erase(nums1.begin()+m,nums1.end());
        nums2.erase(nums2.begin()+n,nums2.end());
        int i=0,j=0;
        for(i=0;i<n&&j<m+i+1;i++){
            while(nums1[j]<nums2[i]) j++;
            if(j>=m+i+1) break;
            nums1.insert(nums1.begin()+j,nums2[i]);
            cout<<j<<" "<<i<<endl;
        }
        while(i<nums2.size()){
            nums1.insert(nums1.end(),nums2[i]);
            i++;
        }
    }
};
