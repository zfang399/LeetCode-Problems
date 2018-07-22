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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> empty;
        // Tree 1
        vector<int> leaves1 = leaves(root1, empty);
        // Tree 2
        vector<int> leaves2 = leaves(root2, empty);

        // Compare
        if(leaves1.size() != leaves2.size()) return false;
        for(int i = 0; i < leaves1.size(); i++){
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }

    vector<int> leaves(TreeNode* root, vector<int> curl){
        if(!root->left && !root->right){
            curl.push_back(root->val);
            return curl;
        }
        vector<int> added;
        if(root->left){
            curl = leaves(root->left,curl);
        }
        if(root->right){
            curl = leaves(root->right,curl);
        }
        return curl;
    }
};
