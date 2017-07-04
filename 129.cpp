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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return getsum(root,0);
    }
    int getsum(TreeNode* root, int now){
        now=now*10+root->val;
        if(!root->left && !root->right) return now;
        int ret=0;
        if(root->left) ret+=getsum(root->left,now);
        if(root->right) ret+=getsum(root->right,now);
        return ret;
    }
};
