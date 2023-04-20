//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int calminPath(int i,int j,vector<vector<int>>& tri,vector<vector<int>>&dp){
        int n=tri.size();
        if(i==n-1){
            return tri[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=tri[i][j]+calminPath(i+1,j,tri,dp);
        int diag=tri[i][j]+calminPath(i+1,j+1,tri,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=0;
        ans=calminPath(0,0,triangle,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends