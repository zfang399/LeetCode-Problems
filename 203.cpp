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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        while(head->val==val){
            head=head->next;
            if(head==NULL) return head;
        }
        ListNode* ret=head;
        while(head->next){
            if(head->next->val==val){
                if(head->next->next) head->next=head->next->next;
                else{
                    head->next=NULL;
                    break;
                }
            }else{
                head=head->next;
            }
        }
        return ret;
    }
};
