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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* l=new ListNode(0),* r=new ListNode(0),*save=head;
        ListNode* sl=l,*sr=r,*m=new ListNode(0);
        ListNode* sm=m;
        head=head->next;
        while(head){
            int x=head->val;
            ListNode* p=head;
            head=head->next;
            if(x<save->val){
                l->next=p;
                l=l->next;
                l->next=NULL;
            }else if(x>save->val){
                r->next=p;
                r=r->next;
                r->next=NULL;
            }else{
                m->next=p;
                m=m->next;
                m->next=NULL;
            }
        }
        save->next=sm->next;
        if(sl->next){
            l=sortList(sl->next);
        }else{
            l=NULL;
        }
        if(sr->next){
            r=sortList(sr->next);
        }else{
            r=NULL;
        }
        ListNode* ans=l;
        if(l){
            while(l->next) l=l->next;
            l->next=save;
        }else{
            ans=save;
        }
        while(save->next) save=save->next;
        save->next=r;
        return ans;
    }
};
