//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int M =1e9+7;
  int fun(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& oG){
        if(i<0||j<0){
            return 0;
        }
        if(oG[i][j]==1){
            return 0;
        }
        if(i==0&&j==0){
            return 1;
        }
        
        if(oG[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int w1=fun(i-1,j,dp,oG);
        int w2=fun(i,j-1,dp,oG);
        return dp[i][j]=(w1+w2)%M;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=fun(n-1,m-1,dp,grid);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends