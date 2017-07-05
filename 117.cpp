/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q1,q2;
        q1.push(root);
        while(q1.size()){
            TreeLinkNode* x=q1.front();
            q1.pop();
            if(x->left) q2.push(x->left);
            if(x->right) q2.push(x->right);
            if(q1.empty()){
                x->next=NULL;
                q1=q2;
                queue<TreeLinkNode*> empty;
                swap(q2,empty);
            }else{
                x->next=q1.front();
            }
        }
    }
};
