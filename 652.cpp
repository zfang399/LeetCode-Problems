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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> m;
        vector<TreeNode*> ans;
        preorder(m,root);
        for(auto e:m){
            if(e.second.size()>1){
                ans.push_back(e.second[0]);
            }
        }
        return ans;
    }
    string preorder(unordered_map<string,vector<TreeNode*>>&m, TreeNode* root){
        if(!root) return "";
        string ret="("+to_string(root->val)+","+preorder(m,root->left)+","+preorder(m,root->right)+")";
        m[ret].push_back(root);
        return ret;
    }
};
