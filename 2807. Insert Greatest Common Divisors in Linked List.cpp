// 2807. Insert Greatest Common Divisors in Linked List
// Leetcode : Medium 10-09-2024

class Solution {
public:
int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr=head;
        ListNode *next=NULL;
        while(curr){
            next=curr->next;
            if(next){
                ListNode *GCD=new ListNode(gcd(curr->val,next->val));
                curr->next=GCD;
                GCD->next=next;
                curr=next;
            }
            else curr=curr->next;
        }
        return head;
    }
};
