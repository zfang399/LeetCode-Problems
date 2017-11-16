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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* onestep = head;
        ListNode* twostep = head;
        bool cycle = false;
        while(onestep != NULL && twostep != NULL){
            onestep = onestep->next;
            if(twostep->next == NULL) return NULL;
            twostep = twostep->next->next;
            if(onestep == twostep){
                cycle = true;
                break;
            }
        }
        if(!cycle) return NULL;
        onestep = head;
        while(onestep != twostep){
            onestep = onestep->next;
            twostep = twostep->next;
        }
        return onestep;
    }
};
