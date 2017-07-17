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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1;
        int depth=deepest(root);
        int ans=pow(2,depth-1)-1;
        return ans+findl(root,depth-1);
    }
    int deepest(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return 1;
        return 1+deepest(root->left);
    }
    int findl(TreeNode* root, int depth){
        if(depth==0) return 1;
        if(deepest(root->right)!=depth) return findl(root->left,depth-1);
        return findl(root->left,depth-1)+findl(root->right,depth-1);
    }
};
