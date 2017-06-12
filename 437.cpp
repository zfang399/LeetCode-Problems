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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        return pathSum(root->left,sum)+pathSum(root->right,sum)+prefixSum(root,0,sum);
    }
private:
    int prefixSum(TreeNode* root, int pre, int& sum){
        if(root==NULL) return 0;
        int now=pre+root->val;
        return (now==sum)+prefixSum(root->left,now,sum)+prefixSum(root->right,now,sum);
    }
};
