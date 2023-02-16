//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&mat,int delr[],int delc[]){
        vis[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<4;i++){
            int nr=row+delr[i];
            int nc=col+delc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&(!vis[nr][nc])&&mat[nr][nc]==1){
                dfs(nr,nc,vis,mat,delr,delc);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &mat) {
         int n=mat.size();
        int m=mat[0].size();
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        // boundry traversal
        for(int j=0;j<m;j++){
            //1 rw
            if(!vis[0][j]&& mat[0][j]==1){
                dfs(0,j,vis,mat,delr,delc);
            }
            //lst rw
            if(!vis[n-1][j]&& mat[n-1][j]==1){
                dfs(n-1,j,vis,mat,delr,delc);
            }
        }
        for(int i=0;i<n;i++){
            //1 cl
            if(!vis[i][0]&& mat[i][0]==1){
                dfs(i,0,vis,mat,delr,delc);
            }
            //lst cl
            if(!vis[i][m-1]&& mat[i][m-1]==1){
                dfs(i,m-1,vis,mat,delr,delc);
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&& mat[i][j]==1){
                    ct++;
                }
            }
        }
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends