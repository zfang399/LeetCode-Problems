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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int,int> m;
        int s=sumt(root,m);
        if(s==0) return m[s]>1;
        return s%2==0 && m.count(s/2);
    }
    int sumt(TreeNode* root, unordered_map<int,int>& m){
        if(!root) return 0;
        int x=root->val+sumt(root->left,m)+sumt(root->right,m);
        m[x]++;
        return x;
    }
};
