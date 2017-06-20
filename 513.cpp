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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        if(depth(root->left)>=depth(root->right)){
            return findBottomLeftValue(root->left);
        }else{
            return findBottomLeftValue(root->right);
        }
    }
private:
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};
