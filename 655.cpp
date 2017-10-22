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
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root){
            vector<vector<string>> ans;
            return ans;
        }
        int lm,rm,dep;
        int d=depth(root);
        vector<vector<string>> ans(d,vector<string>((2<<(d-1))-1,""));
        put(ans,ans[0].size()/2,root,0,2<<(d-2));
        return ans;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    void put(vector<vector<string>>& ans,int pos,TreeNode* now,int nowd,int shift){
        shift/=2;
        ans[nowd][pos]=to_string(now->val);
        if(now->left){
            put(ans,pos-shift,now->left,nowd+1,shift);
        }
        if(now->right){
            put(ans,pos+shift,now->right,nowd+1,shift);
        }
    }
};
