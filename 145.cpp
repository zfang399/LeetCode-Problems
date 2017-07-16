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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> p;
        stack<bool> open;
        p.push(root);
        open.push(false);
        while(p.size()){
            TreeNode* x=p.top();
            p.pop();
            bool o=open.top();
            open.pop();
            if(o){
                ans.push_back(x->val);
            }else{
                p.push(x);
                open.push(true);
                if(x->right){
                    p.push(x->right);
                    open.push(false);
                }
                if(x->left){
                    p.push(x->left);
                    open.push(false);
                }
            }
        }
        return ans;
    }
};
