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
    int length(ListNode* head){
        ListNode* curr=head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
        return head;
       int n=length(head);
       ListNode* tail=head;
       k=k%n;
       while(tail->next!=NULL){
        tail=tail->next;
       }
        tail->next=head;
        ListNode* newTail=head;
        int newTailPosition=n-k-1;
        while(newTailPosition!=0){
            newTail=newTail->next;
            newTailPosition--;
        }
        ListNode* ans=newTail->next;
        newTail->next=NULL;
        return ans;

       } 
};