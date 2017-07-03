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
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int l=0,r=0,ll=0,lr=0,rl=0,rr=0;
        if(root->left){
            l=rob(root->left);
            if(root->left->left) ll=rob(root->left->left);
        	if(root->left->right) lr=rob(root->left->right);
        }
        if(root->right){
            r=rob(root->right);
            if(root->right->left) rl=rob(root->right->left);
        	if(root->right->right) rr=rob(root->right->right);
        }
        return max(root->val+ll+lr+rl+rr,l+r);
    }
 };
