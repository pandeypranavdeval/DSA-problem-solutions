//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int v[], int n)  { 
	    long long sum=0;
	    for(int i=0;i<n;i++){
	        sum+=v[i];
	    }
	    int dp[sum+1];
	    memset(dp,0,sizeof(dp));
	    dp[0]=1;
	    for(int i=0;i<n;i++){
	        for(long long j=sum;j>=v[i];j--){
	            dp[j]|=dp[j-v[i]];
	        }
	    }
	    long long s=sum/2+sum%2;
	    while(dp[s]==0){
	        s--;
	    }
	    return abs((sum-s)-s);
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends