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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i=1;
        ListNode* t=head,*prev=head;
        while(i<m){
            prev=t;
            t=t->next;
            i++;
        }
        ListNode* x=t;
        while(i<n){
            x=x->next;
            i++;
        }
        ListNode* k=x->next;
        x->next=NULL;
        if(m==1){
            ListNode* ret=reverseList(t);
            t->next=k;
            return ret;
        }
        prev->next=reverseList(t);
        t->next=k;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        ListNode* ret=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return ret;
    }
};
