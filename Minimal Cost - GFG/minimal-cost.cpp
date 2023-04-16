//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int ind,vector<int>&dp,int &k,vector<int>& height){
        if(ind==0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int minsteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(ind-j>=0){
                int jump=fun(ind-j,dp,k,height)+abs(height[ind]-height[ind-j]);
                minsteps=min(minsteps,jump);
            }
        }
        return dp[ind]=minsteps;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        int ans=fun(n-1,dp,k,height);
        return ans;
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