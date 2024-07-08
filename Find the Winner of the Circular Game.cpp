// Find the Winner of- the Circular Game
// LeetCode : Medium 08-07-2024

struct Node
    {
        int data;
        struct Node*next;
        struct Node*prev;
        Node(int x)
        {
            data=x;
            next=NULL;
            prev=NULL;
        }
    };
    Node* createlist(int n){
    if (n <= 0) return nullptr;

    Node *head = new Node(1);
    Node *temp = head;   
    for(int i = 2; i <= n; i++)
    {
        Node *t = new Node(i);
        t->prev = temp;
        temp->next = t;
        temp = temp->next;
    }
    head->prev = temp;
    temp->next = head;
    return head;
}

    int findTheWinner(int n, int k) {
        if(n<=0 || k<=0 )return -1;
        Node *head=createlist(n);
        Node *temp=head;
        int count=0;
        while(count<n-1)
        {
            int x=1;
            while(x<k)
            {
            temp=temp->next;
            x++;
            }
            Node *t=temp;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp=temp->next;
            delete t;
            count++;
        }
    int x=temp->data;
    delete temp;
    return x;
    }
