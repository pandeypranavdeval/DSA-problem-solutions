//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int N=1e9+7;
	int solve(int i,int sum,int arr[],vector<vector<int>>&dp){
	    if(i==0){
	        if(sum==0){
	            return 1;
	        }
	        else{
	            return 0;
	        }
	    }
	    int N=1e9+7;
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    if(arr[i-1]<=sum){
	        int pick=solve(i-1,sum-arr[i-1],arr,dp);
	        int notpick=solve(i-1,sum,arr,dp);
	        return dp[i][sum]=(pick+notpick)%N;
	    }
	    else{
	        return dp[i][sum]=solve(i-1,sum,arr,dp)%N;
	    }
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ans=solve(n,sum,arr,dp);
        return ans;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends