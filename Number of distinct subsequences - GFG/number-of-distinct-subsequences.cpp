//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    int N=1e9+7;
	int distinctSubsequences(string s)
	{
	    map<char,int>m;
	    int n=s.size();
	    vector<int>dp(n+1);
	    dp[0]=1;
	    for(int i=1;i<n+1;i++){
	        dp[i]=((2*dp[i-1])%N);
	        if(m[s[i-1]]>0){
	            int j=m[s[i-1]];
	            dp[i]=((dp[i]-dp[j-1])+N)%N;
	        }
	        m[s[i-1]]=i;
	    }
	   // for(int i=0;i<n+1;i++){
	   //     cout<<dp[i]<<" ";
	   // }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends