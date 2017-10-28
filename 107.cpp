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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return ans;
        pushl(root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    void pushl(TreeNode* root, int depth){
        if(root==NULL) return;
        if(depth>=ans.size()){
            vector<int> ins;
            ans.push_back(ins);
        }
        ans[depth].push_back(root->val);
        pushl(root->left,depth+1);
        pushl(root->right,depth+1);
    }
}; 
