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
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* x=q.top();
            q.pop();
            if(x->right) q.push(x->right);
            if(x->left) q.push(x->left);
            x->left=NULL;
            if(q.size()){
                x->right=q.top();
            }else{
                x->right=NULL;
            }
        }
    }
};
