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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        unordered_map<int,int> t;
        return dfs(root,t,k);
    }
    bool dfs(TreeNode* root,unordered_map<int,int>&t,int k){
        if(t[k-root->val]) return true;
        t[root->val]=true;
        bool ret=false;
        if(root->left) ret=ret||dfs(root->left,t,k);
        if(ret) return ret;
        if(root->right) ret=ret||dfs(root->right,t,k);
        return ret;
    }
};
