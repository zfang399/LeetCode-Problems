/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int d=depth(root);
        vector<int> ls;
        while(k>0){
            ls.push_back(d/k);
            d-=d/k;
            k--;
        }
        vector<ListNode*> ans;
        ListNode* prev=root;
        while(ls.size() && root){
            while(ls.back()>1){
                root=root->next;
                ls.back()--;
            }
            ListNode* tmp=root;
            root=root->next;
            tmp->next=NULL;
            ans.push_back(prev);
            prev=root;
            ls.pop_back();
        }
        while(ls.size()){
            ans.push_back(NULL);
            ls.pop_back();
        }
        return ans;
    }
    int depth(ListNode* root){
        if(!root) return 0;
        return 1+depth(root->next);
    }
};
