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
    priority_queue <int> q;
    int getMinimumDifference(TreeNode* root) {
        postorder(root);
        int ans=2147483647;
        int a=q.top();
        int b;
        q.pop();
        while(!q.empty()){
            b=q.top();
            q.pop();
            if(a-b<ans) ans=a-b;
            a=b;
        }
        return ans;
    }
private:
    void postorder(TreeNode* root){
        if(root==NULL) return;
        postorder(root->left);
        postorder(root->right);
        q.push(root->val);
    }
};
