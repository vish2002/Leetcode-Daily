// 725. Split Linked List in Parts
// Leetcode : Medium 08-09-2024

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode *temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        int cut=0;
        int rem=0;
        cut=n/k;
        rem=n%k;
        vector<ListNode *> ans(k);
        temp=head;
        for(int i=0;i<k;i++){
            ans[i]=temp;
            int size = cut + (rem > 0 ? 1 : 0);
            ListNode *prev=NULL;
            while(temp && size){
                prev=temp;
                temp=temp->next;
                size--;
            }
            if(prev)prev->next=NULL;
            if(rem>0)rem--;
        }
        return ans;
        
    }
};
