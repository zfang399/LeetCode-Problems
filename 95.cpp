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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode*> ret;
            return ret;
        }
        return gent(1,n);
    }
    vector<TreeNode*> gent(int f,int r){
        vector<TreeNode*> ret;
        if(f>r){
            ret.push_back(NULL);
            return ret;
        }
        if(f==r){
            TreeNode* x=new TreeNode(f);
            ret.push_back(x);
            return ret;
        }
        vector<TreeNode*> left,right;
        for(int i=f;i<=r;i++){
            left=gent(f,i-1);
            right=gent(i+1,r);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
