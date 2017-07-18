/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode *cur=head;
        RandomListNode *newhead=new RandomListNode(head->label);
        RandomListNode *newh=newhead;
        m[cur]=newh;
        while(cur->next){
            cur=cur->next;
            newh->next=new RandomListNode(cur->label);
            m[cur]=newh->next;
            newh=newh->next;
        }
        cur=head;
        newh=newhead;
        while(cur){
            if(cur->random==NULL){
                newh->random=NULL;
            }else{
                newh->random=m[cur->random];
            }
            cur=cur->next;
            newh=newh->next;
        }
        return newhead;
    }
};
