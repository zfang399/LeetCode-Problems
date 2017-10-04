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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int ret=max(longestUnivaluePath(root->left),longestUnivaluePath(root->right));
        return max(ret,dfs(root->left,root->val)+dfs(root->right,root->val));
    }
    int dfs(TreeNode* root, int val){
        if(!root) return 0;
        if(root->val!=val) return 0;
        return 1+max(dfs(root->left,val),dfs(root->right,val));
    }
};
