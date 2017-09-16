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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return dfs(root,root->val);
    }
    int dfs(TreeNode* root, int rv){
        if(!root) return -1;
        if(root->val==rv){
            int l=dfs(root->left,rv);
            int r=dfs(root->right,rv);
            if(l==-1) return r;
            if(r==-1) return l;
            return min(l,r);
        }else{
            return root->val;
        }
    }
};
