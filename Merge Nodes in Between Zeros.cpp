// 2181. Merge Nodes in Between Zeros
// LeetCode : Medium 04-07-2024

ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=new ListNode(-1);
        ListNode* t=curr;
        ListNode* p=head;
        while(p!=NULL)
        {
            int sum=0;
            bool flag=false;
            while(p->val!=0)
            {
                sum+=p->val;
                p=p->next;
                flag=true;
            }
            if(flag)
            {   p->val=sum;
                curr->next=p;
                curr=p;
            }
            p=p->next;
        }
        return t->next;
    }
