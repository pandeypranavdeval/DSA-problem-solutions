//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int calmaxPath(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&dp){
        int n=mat.size();
        if(i<0||j<0||i>=n||j>=n){
            return -1e9;
        }
        if(i==n-1){
            return mat[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=mat[i][j]+calmaxPath(i+1,j,mat,dp);
        int ldiag=mat[i][j]+calmaxPath(i+1,j-1,mat,dp);
        int rdiag=mat[i][j]+calmaxPath(i+1,j+1,mat,dp);
        
        return dp[i][j]=max(down,max(ldiag,rdiag));
    }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=-1e9;
        for(int j=0;j<n;j++){
            ans=max(ans,calmaxPath(0,j,matrix,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends