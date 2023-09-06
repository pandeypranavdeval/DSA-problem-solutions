//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
	int findMotherVertex(int v, vector<int>adj[])
	{
	    vector<int>vis(v,0);
	    int nd=-1;
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            dfs(i,vis,adj); 
	            nd=i;
	        }
	    }
	    for(int i=0;i<v;i++){
	        vis[i]=0;
	    }
	    dfs(nd,vis,adj);
	    for(int i=0;i<v;i++){
	        if(vis[i]==0){
	            return -1;
	        }
	    }
	    return nd;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends