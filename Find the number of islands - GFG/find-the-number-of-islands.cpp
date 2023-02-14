//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int ro=q.front().first;
            int co=q.front().second;
            q.pop();
            for(int delro=-1;delro<=1;delro++){
                for(int delco=-1;delco<=1;delco++){
                    int nro=ro+delro;
                    int nco=co+delco;
                    if(nro>=0&&nro<n&&nco>=0&&nco<m&&grid[nro][nco]=='1'&&!vis[nro][nco]){
                        vis[nro][nco]=1;
                        q.push({nro,nco});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col]&&grid[row][col]=='1'){
                    ans++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends