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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> x;
        findpath(root,sum,x);
        return ans;
    }
    void findpath(TreeNode* root, int sum, vector<int> x){
        if(!root) return;
        x.push_back(root->val);
        sum-=root->val;
        if(!root->left && !root->right && !sum){
            ans.push_back(x);
        }
        if(root->left) findpath(root->left,sum,x);
        if(root->right) findpath(root->right,sum,x);
    }
};
