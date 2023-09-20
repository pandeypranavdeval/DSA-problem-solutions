//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(ind==0){
            return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        if(arr[ind-1]<=sum){
            dp[ind][sum]=(solve(ind-1,sum-arr[ind-1],arr,dp)||solve(ind-1,sum,arr,dp));
        }
        else{
            dp[ind][sum]=solve(ind-1,sum,arr,dp);
        }
        return dp[ind][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        bool ans=solve(n,sum,arr,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends