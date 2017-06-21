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
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (!root->left && !root->right)) return true;
        if(root->left){
            if(root->left->val>root->val) return false;
        }
        if(root->right){
            if(root->right->val<root->val) return false;
        }
        if(root->left){
            if(maxnum(root->left)>=root->val) return false;
        }
        if(root->right)
            if(minnum(root->right)<=root->val) return false;
        return isValidBST(root->left)&&isValidBST(root->right);
    }
private:
    int maxnum(TreeNode* root){
        if(!root->left && !root->right) return root->val;
        if(!root->left) return max(root->val,maxnum(root->right));
        if(!root->right) return max(root->val,maxnum(root->left));
        return max(root->val,max(maxnum(root->right),maxnum(root->left)));
    }
    int minnum(TreeNode* root){
        if(!root->left && !root->right) return root->val;
        if(!root->left) return min(root->val,minnum(root->right));
        if(!root->right) return min(root->val,minnum(root->left));
        return min(root->val,min(minnum(root->left),minnum(root->right)));
    }
};
