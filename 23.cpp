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
    struct cmp{
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode *>,cmp> q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) q.push(lists[i]);
        }
        if(!q.size()) return NULL;
        ListNode* ans=q.top();
        q.pop();
        if(ans->next) q.push(ans->next);
        ListNode* tmp=ans;
        while(q.size()){
            tmp->next=q.top();
            q.pop();
            tmp=tmp->next;
            if(tmp->next) q.push(tmp->next);
        }
        return ans;
    }
};
