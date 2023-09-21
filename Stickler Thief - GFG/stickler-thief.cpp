//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int solve(int ind,int arr[],int n,vector<int>&dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return arr[0];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=arr[ind]+solve(ind-2,arr,n,dp);
        int notpick=solve(ind-1,arr,n,dp);
        return dp[ind]=max(pick,notpick);
    }
    int FindMaxSum(int arr[], int n){
        vector<int>dp(n,0);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends