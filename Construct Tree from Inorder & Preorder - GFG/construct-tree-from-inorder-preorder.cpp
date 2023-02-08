//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* bldpre(int pre[],int in[],int is,int ie,int &preind){
        if(is>ie){
            return NULL;
        }
        Node* root=new Node(pre[preind]);
        preind++;
        int inIndex=0;
        for(int i=is;i<=ie;i++){
            if(in[i]==root->data){
                inIndex=i;
                break;
            }
        }
        root->left=bldpre(pre,in,is,inIndex-1,preind);
        root->right=bldpre(pre,in,inIndex+1,ie,preind);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preind=0;
        Node* root=bldpre(pre,in,0,n-1,preind);
        return root;
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends