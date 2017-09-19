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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return CreateTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* CreateTree(vector<int>& inorder, vector<int>& postorder, int inf,int inr,int pof,int por){
        if(pof>por) return NULL;
        TreeNode* x=new TreeNode(postorder[por]);
        int pos;
        for(int i=inf;i<=inr;i++){
            if(inorder[i]==x->val){
                pos=i;
                break;
            }
        }
        x->left=CreateTree(inorder,postorder,inf,pos-1,pof,pof+pos-inf-1);
        x->right=CreateTree(inorder,postorder,pos+1,inr,por-inr+pos,por-1);
        return x;
    }
};
