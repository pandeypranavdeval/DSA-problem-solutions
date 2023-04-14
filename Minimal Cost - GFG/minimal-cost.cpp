//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        k=min(k,n);
        vector<int>dp(n);
        dp[0]=0;
        int t=k;
        int i=1;
        while(t--){
            dp[i]=abs(height[i++]-height[0]);
        }
        for(int i=k+1;i<n;i++){
            int v=INT_MAX;
            for(int j=1;j<=k;j++){
                v=min(v,dp[i-j]+abs(height[i]-height[i-j]));
            }
            dp[i]=v;
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends