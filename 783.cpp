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
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.size()){
            TreeNode* now = nodes.front();
            nodes.pop();
            if(now->left) nodes.push(now->left);
            if(now->right) nodes.push(now->right);
            nums.push_back(now->val);
        }
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] - nums[i] < ans) ans = nums[i-1] - nums[i];
        }
        return ans;
    }
};
