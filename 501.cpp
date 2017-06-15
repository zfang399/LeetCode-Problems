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
    map<int,int> count;
    vector<int> findMode(TreeNode* root) {
        preorder(root);
        vector<int> ans;
        int maxc=0;
        for(auto& e:count){
            if(e.second>maxc){
                maxc=e.second;
                ans.erase(ans.begin(),ans.end());
                ans.push_back(e.first);
            }else if(e.second==maxc){
                ans.push_back(e.first);
            }
        }
        return ans;
    }
private:
    void preorder(TreeNode* root){
        if(root==NULL) return;
        count[root->val]++;
        preorder(root->left);
        preorder(root->right);
    }
};
