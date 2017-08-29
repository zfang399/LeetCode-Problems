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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        bool fr=false;
        s.push(root);
        zz(ans,s,fr);
        return ans;
    }
    void zz(vector<vector<int>>& ans, stack<TreeNode*>& s, bool fr){
        vector<int> x;
        ans.push_back(x);
        queue<TreeNode*> tmp;
        while(s.size()){
            TreeNode* t=s.top();
            s.pop();
            ans.back().push_back(t->val);
            if(fr){
                if(t->right) tmp.push(t->right);
                if(t->left) tmp.push(t->left);
            }else{
                if(t->left) tmp.push(t->left);
                if(t->right) tmp.push(t->right);
            }
        }
        while(tmp.size()){
            s.push(tmp.front());
            tmp.pop();
        }
        if(!s.size()) return;
        zz(ans,s,!fr);
    }
};
