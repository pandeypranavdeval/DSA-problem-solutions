//{ Driver Code Starts
//Initial template for C++

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
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node * reverse(Node *head){
        Node *p=head,*q=NULL, *r=NULL;
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    public:
    Node* addOne(Node *head) 
    {
        Node *tt=reverse(head);
        Node *t=tt;
        int c=0;
        while(t){
            if(t->data<9){
                t->data++;
                break;
            }
            else if(t->data==9&&t->next==NULL){
                t->data=1;
                c=1;
                Node *n=new Node(0);
                n->next=tt;
                tt=n;
            }
            else if(t->data==9){
                t->data=0;
                c=1;
            }
            t=t->next;
        }
        Node * ans=reverse(tt);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends