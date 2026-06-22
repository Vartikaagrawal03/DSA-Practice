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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // Check if list matches starting from this tree node
    bool match(ListNode* head, TreeNode* root) {
        if (!head) return true;      // list finished
        if (!root) return false;     // tree ended
        if (head->val != root->val) return false;
        
        return match(head->next, root->left) ||
               match(head->next, root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        
        // check from current node OR move ahead in tree
        return match(head, root) ||
               isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
};