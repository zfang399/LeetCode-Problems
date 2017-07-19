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
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;
        ListNode* ans=head;
        while(head->next->next){
            ListNode* tmp=head->next;
            head->next=getlast(head);
            head->next->next=tmp;
            head=head->next->next;
            if(!head->next) break;
        }
        return;
    }
    ListNode* getlast(ListNode* head){
        if(!head->next) return NULL;
        if(!head->next->next){
            ListNode* ret=head->next;
            head->next=NULL;
            return ret;
        }
        return getlast(head->next);
    }
};
