//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node* rev(node *head){
        node *p=head,*q=NULL,*r=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // int i=0;
        // node *p=head;
        // node *rh=head;
        // while(p){
            
        //     i++;
        //     if(i==k){
        //         p->next=NULL;
        //     }
        //     if(p->next==NULL){
        //         rev(rh);
        //     }
        //     p=p->next;
        // }
        node *nex;
        node *pre=NULL;
        node *cur=head;
        int c=0;
        while(cur!=NULL and c<k){
            nex=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nex;
            c++;
        }
        if(nex!=NULL){
            head->next=reverse(nex,k);
        }
        return pre;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends