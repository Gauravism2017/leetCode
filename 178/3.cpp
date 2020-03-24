/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
        
    }
    bool check(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        return root->val == head->val && (check( head->next, root->left) || check( head->next, root->right));
    }
};