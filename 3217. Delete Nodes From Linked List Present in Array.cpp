// 3217. Delete Nodes From Linked List Present in Array
// Leetcode : Medium 06-09-2024

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hash;
        for (auto num : nums) {
            hash.insert(num);
        }
        ListNode* temp = new ListNode(-1);
        temp->next = NULL;
        ListNode* prev = temp;
        ListNode* curr = head;
        while (curr != NULL) {
            if (!hash.count(curr->val)) {
                prev->next = curr;
                prev = curr;
            } else {
                ListNode* tobedeleted = curr;
                curr = curr->next;
                delete tobedeleted;
                continue;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode* newHead = temp->next;
        delete temp;

        return newHead;
    }
};
