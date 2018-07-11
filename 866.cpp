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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // Follow the path with largest depth
        // When left depth == right depth, return
        while(root){
            int left = get_depth(root->left, 0);
            int right = get_depth(root->right, 0);
            if(left == right) return root;
            root = left > right ? root->left : root->right;
        }
        return root;
    }

    // Get the depth
    int get_depth(TreeNode* root, int depth){
        if(!root) return depth - 1;
        return max(get_depth(root->left, depth + 1), get_depth(root->right, depth + 1));
    }
};
