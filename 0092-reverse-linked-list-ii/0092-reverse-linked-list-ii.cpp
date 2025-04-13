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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* p=dummy;
        for(int i=1;i<left;i++){
            p=p->next;
        }
        ListNode* curr=p->next;
        for(int i=1;i<=right-left;i++){
            ListNode* temp=p->next;
            p->next=curr->next;
            curr->next=curr->next->next;
            p->next->next=temp;
        }
        return dummy->next;
    }
};