//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Disjointset{
    // class of disjoint set ds can be used everywhere ds is needed
    
    public:
        vector<int>rank,parent,size;
        Disjointset(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int findupar(int node){
            if(node==parent[node]){
                return node;
                
            }
            return parent[node]=findupar(parent[node]);
        }
        void findunionbySize(int u,int v){
            int upu=findupar(u);
            int upv=findupar(v);
            if(upu==upv){
                return ;
            }
            if(size[upu]<size[upv]){
                parent[upu]=upv;
                size[upv]+=size[upu];
            }
            else{
                parent[upv]=upu;
                size[upu]+=size[upv];
            }
        }
};

class Solution {
  public:
  
    int numProvinces(vector<vector<int>> adj, int V) {
        Disjointset ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.findunionbySize(i,j);
                }
            }
        }
        int ct=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){
                ct++;
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends