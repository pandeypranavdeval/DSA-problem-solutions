//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node *reverse(Node *head){
      if(head==NULL||head->next==NULL){
          return head;
      }
      Node *newhead=NULL;
      while(head){
         Node *nxt=head->next;
         head->next=newhead;
         newhead=head;
         head=nxt;
      }
     return newhead;
  }

    Node* sortList(Node* head)
    {
        Node *p=NULL,*ptail=NULL,*n=NULL,*ntail=NULL,*q=head;
    while(q){
        if(q->data<0){
            if(ntail==NULL){
                n=q;
                ntail=q;
            }
            else{
                ntail->next=q;
                ntail=ntail->next;
            }
        }
        else{
          if(ptail==NULL){
                p=q;
                ptail=q;
            }
            else{
                ptail->next=q;
                ptail=ptail->next;
            }   
        }
        q=q->next;
    }
     if(ntail)
     ntail->next=NULL;
     if(ptail)
     ptail->next=NULL;
     n=reverse(n);
     ntail=n;
     while(ntail&&ntail->next)
     {
        ntail=ntail->next; 
     }
     if(ntail){
       ntail->next=p;  
       return n;
     }
     return p;

    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends