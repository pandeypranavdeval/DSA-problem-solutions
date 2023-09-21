//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int sum,int nums[],vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(ind==0){
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        if(nums[ind-1]<=sum){
            dp[ind][sum]=(solve(ind-1,sum-nums[ind-1],nums,dp))||solve(ind-1,sum,nums,dp);
        }
        else{
            dp[ind][sum]=solve(ind-1,sum,nums,dp);
        }
        return dp[ind][sum];
    }
    int equalPartition(int n, int nums[]){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1){
            return 0;
        }
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        //for recusive use that above dp 
        //for tabulation use this
        return solve(n,sum,nums,dp);
        //vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
        // for intitalization
        // for(int i=0;i<n+1;i++){
        //     dp[i][0]=true;
        // }
        // for(int j=1;j<sum+1;j++){
        //     dp[0][j]=false;
        // }
        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<sum+1;j++){
        //         if(nums[i-1]<=j){
        //             dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n][sum];
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