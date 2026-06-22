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
    
    // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        // Step 1: reverse
        head = reverse(head);
        
        // Step 2: remove nodes
        int maxSoFar = head->val;
        ListNode* curr = head;
        
        while (curr && curr->next) {
            if (curr->next->val < maxSoFar) {
                // remove node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxSoFar = curr->val;
            }
        }
        
        // Step 3: reverse back
        return reverse(head);
    }
};