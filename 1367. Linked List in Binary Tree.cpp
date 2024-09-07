// 1367. Linked List in Binary Tree
// Leetcode : Medium 07-09-2024

class Solution {
public:
    bool DFS(TreeNode* root,ListNode* temp,ListNode* head){
        if(!temp){
            return true;
        }
        if(!root)return false;

        if(temp->val == root->val)temp=temp->next;
        else if(head->val == root->val)head=head->next;
        else temp=head;

        return DFS(root->left,temp,head)||DFS(root->right,temp,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return DFS(root,head,head);
    }
};
