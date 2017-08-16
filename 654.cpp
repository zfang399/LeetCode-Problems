/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        if(nums.size()==1){
            TreeNode* ret=new TreeNode(nums[0]);
            return ret;
        }
        return c(nums,0,nums.size()-1);
    }
    TreeNode* c(vector<int>& nums,int f,int r){
        if(f>r) return NULL;
        if(f==r){
            TreeNode* ret=new TreeNode(nums[f]);
            return ret;
        }
        int maxn=nums[f],maxi=f;
        for(int i=f+1;i<=r;i++){
            if(nums[i]>maxn){
                maxn=nums[i];
                maxi=i;
            }
        }
        TreeNode* ret=new TreeNode(nums[maxi]);
        ret->left=c(nums,f,maxi-1);
        ret->right=c(nums,maxi+1,r);
        return ret;
    }
};
