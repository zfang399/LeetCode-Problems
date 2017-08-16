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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        stack<int> s;
        ListNode* root=head;
        s.push(head->val);
        while(head->next){
            head=head->next;
            s.push(head->val);
        }
        if(root->val!=s.top()) return false;
        s.pop();
        while(root->next){
            root=root->next;
            if(root->val!=s.top()) return false;
            s.pop();
        }
        return true;
    }
};
