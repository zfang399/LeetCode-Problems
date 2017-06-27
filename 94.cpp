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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        stack<bool> o;
        vector<int> ans;
        if(!root) return ans;
        s.push(root);
        o.push(false);
        while(s.size()){
            TreeNode* x=s.top();
            bool visited=o.top();
            s.pop();
            o.pop();
            if(visited){
                ans.push_back(x->val);
            }else{
                if(x->right){
                    s.push(x->right);
                    o.push(false);
                }
                s.push(x);
                o.push(true);
                if(x->left){
                    s.push(x->left);
                    o.push(false);
                }
            }
        }
        return ans;
    }
};
