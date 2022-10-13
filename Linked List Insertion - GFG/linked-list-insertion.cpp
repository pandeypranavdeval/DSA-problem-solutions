//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
  }  
  cout<<"\n";
} 



// } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node* temp=head;
       Node *np=new Node(x);
       np->next=temp;
       head=np;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node *temp=head;
       Node *ad=NULL;
       while(temp!=NULL){
           ad=temp;
           temp=temp->next;
       }
       if(ad==NULL){
           Node *q=new Node(x);
           head=q;
           return head;
       }
       else{
           Node *q=new Node(x);
           q->next=NULL;
           ad->next=q;
           return head;
       }
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            Solution obj;
            if(indicator)
                head = obj.insertAtEnd(head, data); 
            else
                head = obj.insertAtBegining(head, data);
        }
        printList(head); 
    }
    return 0; 
} 


// } Driver Code Ends