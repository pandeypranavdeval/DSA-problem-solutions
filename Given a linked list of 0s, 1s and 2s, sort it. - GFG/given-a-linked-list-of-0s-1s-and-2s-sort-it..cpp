//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *t=head;
        Node *one=NULL,*onet=NULL;
        Node *zero=NULL,*zerot=NULL;
        Node *two=NULL,*twot=NULL;
        while(t!=NULL){
            if(t->data==0){
                if(zero==NULL){
                    zero=t;
                    zerot=t;
                }
                else{
                    zerot->next=t;
                    zerot=zerot->next;
                }
            }
            else if(t->data==1){
                if(one==NULL){
                    one=t;
                    onet=t;
                }
                else{
                    onet->next=t;
                    onet=onet->next;
                }
            }
            else if(t->data==2){
                if(two==NULL){
                    two=t;
                    twot=t;
                }
                else{
                    twot->next=t;
                    twot=twot->next;
                }
            }
            t=t->next;
        }
        
        Node *ans=NULL;
        Node *anst=NULL;
        if(zero){
            ans=zero;
            anst=zerot;
        }
        if(one){
            if(anst){
                anst->next=one;
                anst=onet;
            }
            else{
                ans=one;
                anst=onet;
            }
        }
        if(two){
            if(anst){
                anst->next=two;
                anst=twot;
            }
            else{
                ans=two;
                anst=twot;
            }
        }
        anst->next=NULL;
        return ans;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends