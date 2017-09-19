/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        leftline(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp=st.top();
        st.pop();
        if(tmp->right){
            leftline(tmp->right);
        }
        return tmp->val;
    }

    void leftline(TreeNode* root){
        if(!root) return;
        st.push(root);
        while(root->left){
            root=root->left;
            st.push(root);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
