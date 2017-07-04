/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        int tot=countl(head);
        if(tot==1){
            TreeNode* ret=new TreeNode(head->val);
            return ret;
        }
        int mid=(tot-1)/2;
        ListNode* t=new ListNode(0);
        if(mid==0){
            t=head;
        }else{
            t=getnth(head,mid);
        }
        TreeNode* ret=new TreeNode(t->next->val);
        ret->right=sortedListToBST(t->next->next);
        t->next=NULL;
        ret->left=sortedListToBST(head);
        return ret;
    }
    int countl(ListNode* head){
        if(head->next) return countl(head->next)+1;
        return 1;
    }
    ListNode* getnth(ListNode* head, int n){
        if(n==1) return head;
        return getnth(head->next,n-1);
    }
};
