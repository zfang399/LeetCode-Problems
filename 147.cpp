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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* ret=head, * now=head;
        while(now->next){
            int x=now->next->val;
            if(x>now->val){
                now=now->next;
                continue;
            }
            ListNode* s=ret,*prev=NULL;
            while(s->val<x){
                prev=s;
                s=s->next;
            }
            if(prev==NULL){
                ListNode *t=now->next->next;
                now->next->next=s;
                ret=now->next;
                now->next=t;
            }else{
                ListNode *t=now->next->next;
                now->next->next=s;
                prev->next=now->next;
                now->next=t;
            }
        }
        return ret;
    }
};
