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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return NULL;
        ListNode *Ap=headA,*Bp=headB;
        while(Ap && Bp && Ap!=Bp){
            Ap=Ap->next;
            Bp=Bp->next;
            if(Ap==Bp) return Ap;
            if(Ap==NULL) Ap=headB;
            if(Bp==NULL) Bp=headA;
        }
        return Ap;
    }
};
