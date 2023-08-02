//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
         if(A[0][0]!=1 || A[X][Y]!=1)
        return -1;
        
        vector<vector<int>> vis(N,vector<int>(M,0));
        int dis=0;
        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0]=1;
        
        while(!q.empty())
        {
            int s=q.size();
            
            for(int i=0;i<s;i++)
            {
                int x=q.front()[0];
                int y= q.front()[1];
                q.pop();
                if(x==X && y==Y)
                    return dis;
                
                int dirs[4][4]= {{-1,0},{1,0},{0,-1},{0,1}};
                for(int i=0;i<4;i++)
                {
                    int dx= x+dirs[i][0];
                    int dy= y+dirs[i][1];
                    
                    if(dx>=0 && dx<N && dy>=0 && dy<M && !vis[dx][dy] && A[dx][dy]==1)
                    {
                        q.push({dx,dy});
                        vis[dx][dy]=1;
                    }
                }
            }
            
            dis++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends