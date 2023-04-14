//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int i,vector<int>& height,vector<int>&dp){
        if(i==0){
            return 0;
        }
        if(i==1){
            return abs(height[i]-height[i-1]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int v1=fun(i-1,height,dp)+abs(height[i]-height[i-1]);
        int v2=fun(i-2,height,dp)+abs(height[i]-height[i-2]);
        return dp[i]=min(v1,v2);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        int ans=0;
        ans=fun(n-1,height,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends