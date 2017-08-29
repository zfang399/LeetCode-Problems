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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lm;
        int ans=0;
        dfs(root,ans,0,1,lm);
        return ans;
    }
    void dfs(TreeNode* root, int& ans, int level, int num, vector<int>& lm){
        if(!root) return;
        if(level>=lm.size()) lm.push_back(num);
        ans=max(ans,num-lm[level]+1);
        dfs(root->left,ans,level+1,num*2,lm);
        dfs(root->right,ans,level+1,num*2+1,lm);
    }
};
