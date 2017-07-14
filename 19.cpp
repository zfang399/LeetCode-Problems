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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        s.push(head);
        ListNode* ret=head;
        while(head->next){
            head=head->next;
            s.push(head);
        }
        int i=1;
        ListNode* prev=NULL;
        while(i<n){
            prev=s.top();
            s.pop();
            i++;
        }
        s.pop();
        if(s.size()){
            s.top()->next=prev;
            return ret;
        }else{
            return prev;
        }
    }
};
