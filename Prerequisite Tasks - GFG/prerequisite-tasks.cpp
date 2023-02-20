//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int v, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[v];
	    for(auto it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    int indeg[v]={0};
	    for(int i=0;i<v;i++){
	        for(auto it:adj[i]){
	            indeg[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<v;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    int ct=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ct++;
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(indeg[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return ct==v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends