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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
private:
    void dfs(TreeNode* root,string s){
        if(root==NULL) return;
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        dfs(root->left,s+to_string(root->val)+"->");
        dfs(root->right,s+to_string(root->val)+"->");
    }
};
