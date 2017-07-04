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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(q1.size()){
            TreeNode* x=q1.front();
            q1.pop();
            if(x->left) q2.push(x->left);
            if(x->right) q2.push(x->right);
            if(q1.size()==0){
                ans.push_back(x->val);
                q1=q2;
                queue<TreeNode*> empty;
                swap(q2,empty);
            }
        }
        return ans;
    }
};
