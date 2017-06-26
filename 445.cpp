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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> na,nb;
        while(l1){
            na.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            nb.push_back(l2->val);
            l2=l2->next;
        }
        int as=na.size()-1,bs=nb.size()-1,ex=0;
        ListNode* root=NULL,*prev=NULL;
        while(as>=0 && bs>=0){
            int sum=na[as]+nb[bs]+ex;
            ex=sum/10;
            sum%=10;
            root=new ListNode(sum);
            root->next=prev;
            prev=root;
            as--;
            bs--;
        }
        while(as>=0){
            int sum=na[as]+ex;
            ex=sum/10;
            sum%=10;
            root=new ListNode(sum);
            root->next=prev;
            prev=root;
            as--;
        }
        while(bs>=0){
            int sum=nb[bs]+ex;
            ex=sum/10;
            sum%=10;
            root=new ListNode(sum);
            root->next=prev;
            prev=root;
            bs--;
        }
        if(ex){
            root=new ListNode(ex);
            root->next=prev;
            prev=root;
        }
        return prev;
    }
};
