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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* hs=new ListNode(x), *hb=new ListNode(x);
        ListNode* rs=hs, *rb=hb;
        ListNode* root=new ListNode(x);
        root->next=head;
        while(root->next){
            root=root->next;
            if(root->val<x){
                ListNode* l=new ListNode(root->val);
                hs->next=l;
                hs=l;
            }else{
                ListNode* l=new ListNode(root->val);
                hb->next=l;
                hb=l;
            }
        }
        if(!rs->next){
            return rb->next;
        }else if(!rb->next){
            return rs->next;
        }else{
            hs->next=rb->next;
            return rs->next;
        }
    }
};
