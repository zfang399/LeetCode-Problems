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
int presum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
private:
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->right);
        root->val+=presum;
        presum+=(root->val-presum);
        inorder(root->left);
    }
};
