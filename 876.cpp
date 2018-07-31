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
    ListNode* middleNode(ListNode* head) {
        // Get depth
        int dep = depth(head);
        int half = dep/2;

        // Get node;
        while(half > 0){
            head = head->next;
            half--;
        }
        return head;
    }

    int depth(ListNode* head){
        if(!head->next) return 1;
        return depth(head->next) + 1;
    }
};
