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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* a=l1;
    ListNode* b=l2;
    ListNode* ans=new ListNode(0);
    ListNode* curr=ans;
     int carry=0;
     while(a!=NULL||b!=NULL){
        int x=(a!=NULL)? a->val:0;
        int y=(b!=NULL)? b->val:0;
        int sum=x+y+carry;
        carry=sum/10;

        curr->next=new ListNode(sum%10);
        curr=curr->next;

        if(a!=NULL){
            a=a->next;
        }
        if(b!=NULL){
            b=b->next;
        }


     }
     if(carry>0){
        curr->next=new ListNode(carry);
     }
     return ans->next;

    }
};