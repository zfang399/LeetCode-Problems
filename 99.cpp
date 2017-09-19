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
    TreeNode* fe=NULL;
    TreeNode* se=NULL;
    TreeNode* prev=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        inorder(root);

        int t=fe->val;
        fe->val=se->val;
        se->val=t;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(!fe && prev->val>=root->val){
            fe=prev;
        }
        if(fe && prev->val>=root->val){
            se=root;
        }
        prev=root;
        inorder(root->right);
    }
};
