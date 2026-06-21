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
#include <cstdlib>

class Solution {
private:
    ListNode* headNode;

public:
    Solution(ListNode* head) {
        headNode = head;
    }
    
    int getRandom() {
        int result = headNode->val;
        ListNode* curr = headNode;
        int i = 1;
        
        while (curr != nullptr) {
            // Generate a random number from 1 to i. 
            // If it's 1, update the result with the current node's value.
            if (rand() % i == 0) { 
                result = curr->val;
            }
            i++;
            curr = curr->next;
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */