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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL){
            if(t==NULL){
                return true;
            }else{
                return false;
            }
        }else if(t==NULL){
            return false;
        }
        return isSame(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
private:
    bool isSame(TreeNode* a, TreeNode* b){
        if(a==NULL){
            if(b==NULL){
                return true;
            }else{
                return false;
            }
        }else if (b==NULL){
            return false;
        }
        return (a->val==b->val)&&isSame(a->left,b->left)&&isSame(a->right,b->right);
    }
};
