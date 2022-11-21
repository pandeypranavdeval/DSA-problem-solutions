//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int i,int target,int n,vector<int>&op,vector<vector<int>>&ans){
	    if(i==0){
	        if(target==0){
	            
	                ans.push_back(op);
	            
	        }
	        return ;
	    }
	    if(target>=i){
	        op.push_back(i);
	        solve(i,target-i,n,op,ans);
	        op.pop_back();
	    }
	    solve(i-1,target,n,op,ans);
	    return ;
	}

    vector<vector<int>> UniquePartitions(int n) {
        vector<int>op;
        vector<vector<int>>ans;
        solve(n,n,n,op,ans);
        
        return ans;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends