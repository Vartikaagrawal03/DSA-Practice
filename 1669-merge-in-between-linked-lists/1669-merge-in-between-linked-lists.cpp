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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        // Step 1: reach node before 'a'
        ListNode* prevA = list1;
        for (int i = 0; i < a - 1; i++) {
            prevA = prevA->next;
        }
        
        // Step 2: reach node at 'b'
        ListNode* curr = prevA;
        for (int i = 0; i < b - a + 2; i++) {
            curr = curr->next;
        }
        ListNode* nextB = curr;
        
        // Step 3: connect prevA to list2
        prevA->next = list2;
        
        // Step 4: go to end of list2
        ListNode* tail = list2;
        while (tail->next) {
            tail = tail->next;
        }
        
        // Step 5: connect tail of list2 to nextB
        tail->next = nextB;
        
        return list1;
    }
};