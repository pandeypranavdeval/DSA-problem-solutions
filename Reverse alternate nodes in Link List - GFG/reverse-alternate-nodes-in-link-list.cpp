//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    struct Node* rev(struct Node *head){
        Node *p=head,*q=NULL,*r=NULL;
        while(p!=0){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    void rearrange(struct Node *odd){
        Node *nw=NULL,*r=NULL;
        Node *p=odd, *q=odd->next;
        while(q!=NULL){
            //cout<<q->data<<" ";
            if(nw==NULL){
                nw=q;
                r=q;
            }
            else{
                r->next=q;
                r=r->next;
                //r->next=NULL;
            }
            p->next=q->next;
            p=p->next;
            if(q->next==NULL){
                break;
            }
            if(q->next->next==NULL){
                q->next=NULL;
                break;
            }
            q=q->next->next;
        }
        // cout<<q->data;
        // cout<<p->data;
        nw=rev(nw);
        while(odd){
            if(odd->next==NULL){
                odd->next=nw;
                break;
            }
            odd=odd->next;
        }
        //cout<<endl;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends