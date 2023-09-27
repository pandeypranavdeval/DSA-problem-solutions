//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int N=1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int ts=0;
        for(int i=0;i<n;i++){
            ts+=arr[i];
        }
        if((ts+d)%2!=0){
            return 0;
        }
        int sum=(ts+d)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        // for(int i=0;i<n+1;i++){
        //     dp[i][0]=1;
        // }
        dp[0][0]=1;
        for(int j=1;j<sum+1;j++){
            dp[0][j]=0;
        }
        // tabilation approcah
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%N;
                }
                else{
                    dp[i][j]=(dp[i-1][j])%N;
                }
            }
        }
        return dp[n][sum];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends