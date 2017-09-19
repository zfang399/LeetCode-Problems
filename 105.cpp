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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return CreateTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* CreateTree(vector<int>& preorder, vector<int>& inorder,int prf,int prr, int inf, int inr){
        if(inf>inr) return NULL;
        TreeNode* x=new TreeNode(preorder[prf]);
        int pos;
        for(int i=inf;i<=inr;i++){
            if(x->val==inorder[i]){
                pos=i;
                break;
            }
        }
        x->left=CreateTree(preorder,inorder,prf+1,prf+pos-inf,inf,pos-1);
        x->right=CreateTree(preorder,inorder,prr-inr+pos+1,prr,pos+1,inr);
        return x;
    }
};
