class NumArray {
public:
    vector<int> pre;
    vector<int> cop;
    vector<int> c;
    NumArray(vector<int> nums) {
        if(nums.size()==0) return;
        pre.push_back(nums[0]);
        cop.push_back(nums[0]);
        c.push_back(0);
        for(int i=1;i<nums.size();i++){
            c.push_back(0);
            cop.push_back(nums[i]);
            pre.push_back(pre[i-1]+nums[i]);
        }
    }

    void update(int i, int val) {
        c[i]=val-cop[i];
    }

    int sumRange(int i, int j) {
        int ret;
        if(i==0) ret=pre[j];
        else ret=pre[j]-pre[i-1];
        for(int k=i;k<=j;k++) ret+=c[k];
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
