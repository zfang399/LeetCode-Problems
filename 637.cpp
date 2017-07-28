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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        queue<TreeNode*> vals;
        queue<int> d;
        vals.push(root);
        d.push(1);
        double nowd=1,nowsum=0,nownum=0;
        while(vals.size()){
            int topd=d.front();
            TreeNode* t=vals.front();
            d.pop();
            vals.pop();
            if(topd!=nowd){
                nowd=topd;
                ans.push_back(nowsum/nownum);
                nowsum=t->val;
                nownum=1;
            }else{
                nowsum+=t->val;
                nownum++;
            }
            if(t->left){
                vals.push(t->left);
                d.push(topd+1);
            }
            if(t->right){
                vals.push(t->right);
                d.push(topd+1);
            }
        }
        ans.push_back(nowsum/nownum);
        return ans;
    }
};
