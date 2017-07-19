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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(k==0) return head;
        int d=getd(head);
        k%=d;
        if(k==0) return head;
        k=d-k;
        ListNode* prev=getx(head,k);
        ListNode* ans=prev->next;
        ListNode* last=ans;
        while(last->next) last=last->next;
        last->next=head;
        prev->next=NULL;
        return ans;
    }
    int getd(ListNode* head){
        int ret=1;
        while(head->next){
            head=head->next;
            ret++;
        }
        return ret;
    }
    ListNode* getx(ListNode* head,int x){
        if(x==1) return head;
        return getx(head->next,x-1);
    }
};
