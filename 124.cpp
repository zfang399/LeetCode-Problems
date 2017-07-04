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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        int x=inorder(root);
        return ans;
    }
    int inorder(TreeNode* root){
        int ret=INT_MIN;
        int l=0,r=0;
        if(root->left){
            l=inorder(root->left);
            ret=max(ret,root->val+l);
        }
        if(root->right){
            r=inorder(root->right);
            ret=max(ret,root->val+r);
        }
        ret=max(root->val,ret);
        if(ret>ans) ans=ret;
        if(l+r+root->val>ans) ans=l+r+root->val;
        return ret;
    }
};
