//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({x-1,y-1});
        vis[x-1][y-1]=1;
        int ct=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        while(!q.empty()){
            //cout<<a<<" "<<b<<"\n";
            bool flag=false;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                int nrow=a+delr[j];
                int ncol=b+delc[j];
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0){
                        flag=true;
                        
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }   
                }
            }
            if(flag){
                ct++;
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends