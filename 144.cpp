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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x=q.top();
            q.pop();
            ans.push_back(x->val);
            if(x->right) q.push(x->right);
            if(x->left) q.push(x->left);
        }
        return ans;
    }
};
