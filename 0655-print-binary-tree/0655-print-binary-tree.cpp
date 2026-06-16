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
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    void fill(TreeNode* root, vector<vector<string>>& res, int row, int left, int right) {
        if (!root) return;
        
        int mid = (left + right) / 2;
        res[row][mid] = to_string(root->val);
        
        fill(root->left, res, row + 1, left, mid - 1);
        fill(root->right, res, row + 1, mid + 1, right);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int rows = height + 1;
        int cols = pow(2, rows) - 1;
        
        vector<vector<string>> res(rows, vector<string>(cols, ""));
        
        fill(root, res, 0, 0, cols - 1);
        
        return res;
    }
};