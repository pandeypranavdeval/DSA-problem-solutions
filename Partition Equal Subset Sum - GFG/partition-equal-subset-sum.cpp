//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int sum,int arr[],vector<vector<int>>&dp){
	    if(i==0){
	        if(sum==0){
	            return 1;
	        }
	        else{
	            return 0;
	        }
	    }
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    if(arr[i-1]<=sum){
	        int pick=solve(i-1,sum-arr[i-1],arr,dp);
	        int notpick=solve(i-1,sum,arr,dp);
	        return dp[i][sum]=(pick+notpick);
	    }
	    else{
	        return dp[i][sum]=solve(i-1,sum,arr,dp);
	    }
	}
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum&1){
            return 0;
        }
        sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ans=solve(n,sum,arr,dp);
        if(ans){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends