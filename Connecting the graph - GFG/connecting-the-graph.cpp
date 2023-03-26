//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


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
    int Solve(int n, vector<vector<int>>& edge){
        Disjointset ds(n);
        int ext=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findupar(u)==ds.findupar(v)){
                ext++;
            }
            else{
                ds.findunionbySize(u,v);
            }
        }
        int ctC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                ctC++;
            }
        }
        if(ext>=ctC-1){
            return ctC-1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends