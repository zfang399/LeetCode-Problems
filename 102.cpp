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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        preorder(root,0);
        return ans;
    }
    void preorder(TreeNode* root, int depth){
        if(depth+1>ans.size()){
            vector<int> x;
            ans.push_back(x);
        }
        ans[depth].push_back(root->val);
        if(root->left) preorder(root->left,depth+1);
        if(root->right) preorder(root->right, depth+1);
    }
};
