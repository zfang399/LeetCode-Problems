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
unordered_map <int,int> sumcount;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        sumcount[findsum(root)]++;
        int most=INT_MIN;
        for(auto e : sumcount){
            if(e.second>most){
                ans.erase(ans.begin(),ans.end());
                ans.push_back(e.first);
                most=e.second;
            }else if(e.second==most){
                ans.push_back(e.first);
            }
        }
        return ans;
    }
private:
    int findsum(TreeNode* root){
        int l=0,r=0;
        if(root->left){
            l=findsum(root->left);
            sumcount[l]++;
        }
        if(root->right){
            r=findsum(root->right);
            sumcount[r]++;
        }
        return root->val+l+r;
    }
};
