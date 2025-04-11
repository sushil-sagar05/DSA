/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        Node* prev=NULL;
        Node* newHead=NULL;
        while(curr){
            Node* temp = new Node(curr->val);
            mp[curr]=temp;
            if(newHead==NULL){
                newHead=temp;
                prev=newHead;
            }else{
                prev->next=temp;
                prev=temp;
            }
            curr=curr->next;
        }
        //Random pointers filling starts
        curr =head;
        Node* newCurr = newHead;
        while(curr){
            if(curr->random==NULL){
                newCurr->random=NULL;
            }else{
                Node* randomOriginalNode=curr->random;
                Node* deepCopyCorrespondingRandomNode=mp[randomOriginalNode];
                newCurr->random=deepCopyCorrespondingRandomNode;
            }
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;
        
    }
};