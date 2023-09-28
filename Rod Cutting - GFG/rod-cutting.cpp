//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class Solution{
  public:
    int solve(int ind,int w,int price[],vector<vector<int>>&dp){
        if(ind==0||w==0){
            return 0;
        }
        // recursive solution
        if(dp[ind][w]!=-1){
            return dp[ind][w];
        }
        if(ind<=w){
            dp[ind][w]=max(price[ind-1]+solve(ind,w-ind,price,dp),solve(ind-1,w,price,dp));
        }
        else{
            dp[ind][w]=solve(ind-1,w,price,dp);
        }
        return dp[ind][w];
    }
    int cutRod(int price[], int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(n,n,price,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends