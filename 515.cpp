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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*, int> p(root,0);
        q.push(p);
        int depth=0,m=INT_MIN;
        while(!q.empty()){
            pair<TreeNode*, int> x=q.front();
            q.pop();
            if(x.second==depth){
                m=max(m,x.first->val);
            }else{
                depth++;
                ans.push_back(m);
                m=x.first->val;
            }
            if(x.first->left){
                q.push(make_pair(x.first->left,depth+1));
            }
            if(x.first->right){
                q.push(make_pair(x.first->right,depth+1));
            }
        }
        ans.push_back(m);
        return ans;
    }
private:
};
