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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> ans;
        if(root == NULL){
            TreeNode* x = NULL;
            ans.push_back(x);
            ans.push_back(x);
            return ans;
        }
        if(root->val == V){
            ans.push_back(root);
            TreeNode* x = NULL;
            ans.push_back(x);
            return ans;
        }
        TreeNode* orig = root;
        TreeNode* last = root;
        while(root!=NULL){
            if(V == root->val && V > last->val){
                last->right = root->left;
                root->left = NULL;
                ans.push_back(root);
                ans.push_back(orig);
                return ans;
            }else if(V == root->val && V < last->val){
                last->left = root->right;
                root->right = NULL;
                ans.push_back(root);
                ans.push_back(orig);
                return ans;
            }else{
                if(V < root->val){
                    last = root;
                    root = root->left;
                }else{
                    last = root;
                    root = root->right;
                }
            }
        }

        root = orig;
        last = root;
        while(root!=NULL){
            if((V > last->val && V < root->val)){
                last->right = root->left;
                root->left = NULL;
                ans.push_back(root);
                ans.push_back(orig);
                return ans;
            }else if(V < last->val && V > root->val){
                last->left = root->right;
                root->right = NULL;
                ans.push_back(root);
                ans.push_back(orig);
                return ans;
            }else{
                if(V < root->val){
                    last = root;
                    root = root->left;
                }else{
                    last = root;
                    root = root->right;
                }
            }
        }

        ans.push_back(orig);
        TreeNode* x = NULL;
        ans.push_back(x);
        return ans;
    }
};
