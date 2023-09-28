//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int w,int val[], int wt[],vector<vector<int>>&dp){
        if(ind==0||w==0){
            return 0;
        }
        if(dp[ind][w]!=-1){
            return dp[ind][w];
        }
        if(wt[ind-1]<=w){
            dp[ind][w]=max(val[ind-1]+solve(ind,w-wt[ind-1],val,wt,dp),
            solve(ind-1,w,val,wt,dp));
        }
        else{
            dp[ind][w]=solve(ind-1,w,val,wt,dp);
        }
        return dp[ind][w];
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        int ans=solve(n,w,val,wt,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends