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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*> t;
        stack<bool> open;
        t.push(root);
        open.push(false);
        int seen=0;
        while(t.size()){
            TreeNode* x=t.top();
            t.pop();
            if(open.top()){
                seen++;
                open.pop();
                if(seen==k){
                    return x->val;
                }
            }else{
                open.pop();
                if(x->right){
                    t.push(x->right);
                    open.push(false);
                }
                t.push(x);
                open.push(true);
                if(x->left){
                    t.push(x->left);
                    open.push(false);
                }
            }
        }
    }
};
