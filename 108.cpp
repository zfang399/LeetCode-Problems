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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return insertnode(0,nums.size(),nums);
    }
private:
    TreeNode* insertnode(int f,int r,vector<int>& nums){
        cout<<f<<" "<<r<<endl;
        if(f==r && f!=0) return NULL;
        if(f==nums.size()) return NULL;
        if(f==r || f==r-1){
            TreeNode* now=new TreeNode(nums[f]);
            return now;
        }
        TreeNode* now=new TreeNode(nums[(f+r)/2]);
        now->left=insertnode(f,(f+r)/2,nums);
        now->right=insertnode((f+r)/2+1,r,nums);
        return now;
    }
};
