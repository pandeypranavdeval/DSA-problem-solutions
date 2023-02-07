//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
void markparents(Node *node,unordered_map<Node*,Node*>&parent){
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node *cur=q.front();
            q.pop();
            if(cur->left){
                parent[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    
    Node* preorder(Node* node,int &target){
        if(!node){
            return node;
        }
        if(node->data==target){
            return node;
        }
        Node *l=preorder(node->left,target);
        
        Node *r=preorder(node->right,target);
        if(l){
            return  l;
        }
        else if(r){
            return r;
            
        }
        else{
            return NULL;
        }
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        Node *tar=preorder(root,target);;
        
        unordered_map<Node*,Node*>parent;
        markparents(root,parent);
        
        
        //if(tar)cout<<tar->data;
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(tar);
        vis[tar]=true;
        int curlvl=0;
        while(!q.empty()){
            int size=q.size();
            if(curlvl++ == k){
                break;
            }
            for(int i=0;i<size;i++){
                Node* cur=q.front();
                q.pop();
                if(cur->left&&!vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right&&!vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parent[cur]&&!vis[parent[cur]]){
                    q.push(parent[cur]);
                    vis[parent[cur]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends