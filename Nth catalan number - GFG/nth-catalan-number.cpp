//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        long long v[n+1]={0};
        int N=1e9+7;
        v[0]=1;
        v[1]=1;
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                v[i]=(v[i]+(v[j]*v[i-1-j])%N)%N;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" ";
        // }
        return v[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends