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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* newroot=new TreeNode(v);
            newroot->left=root;
            return newroot;
        }
        helper(root,v,d-1);
        return root;
    }
    void helper(TreeNode* root, int v, int l){
        if(l==1){
            TreeNode *nl=new TreeNode(v);
            TreeNode *nr=new TreeNode(v);
            if(root->left) nl->left=root->left;
            if(root->right) nr->right=root->right;
            root->left=nl;
            root->right=nr;
            return;
        }
        if (root->left) helper(root->left,v,l-1);
        if (root->right) helper(root->right,v,l-1);
    }
};
