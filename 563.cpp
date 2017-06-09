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
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        int l=findTilt(root->left);
        int r=findTilt(root->right);
        return l+r+int(abs(sum(root->left)-sum(root->right)));
    }
private:
    int sum(TreeNode* root){
        if(root==NULL) return 0;
        return sum(root->left)+sum(root->right)+root->val;
    }
};
