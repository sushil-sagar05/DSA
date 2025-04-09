/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* p=head;
        ListNode* q=NULL;
        ListNode* r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=reverseList(slow);
        ListNode* curr = head;
        while(rev->next!=NULL){
            ListNode* tempcurr = curr->next;
            curr->next=rev;
            ListNode* temprev=rev->next;
            rev->next=tempcurr;
            curr=tempcurr;
            rev=temprev;
        }
    }
};