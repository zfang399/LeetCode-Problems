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
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s;
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        if((root->left && !root->right)||(!root->left && root->right)) return false;
        s.push(root->right),s.push(root->left);
        while(!s.empty()){
            TreeNode* l=s.top();
            s.pop();
            TreeNode* r=s.top();
            s.pop();
            if(l->val!=r->val) return false;
            if(r->right!=NULL && l->left!=NULL){
                s.push(r->right),s.push(l->left);
            }else if(!(r->right==NULL && l->left==NULL)){
                return false;
            }
            if(r->left!=NULL && l->right!=NULL){
                s.push(r->left),s.push(l->right);
            }else if(!(r->left==NULL && l->right==NULL)){
                return false;
            }
        }
        return true;
    }
};
