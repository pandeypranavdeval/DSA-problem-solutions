//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col,vector<string>&board,vector<vector<int>>&ans,vector<int>&leftrow,vector<int>&uppdiag,vector<int>&lowdiag,int n){
        if(col==n){
            vector<int>vt;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]=='Q'){
                        vt.push_back(j+1);
                    }
                }
            }
            ans.push_back(vt);
            return ;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0&&lowdiag[row+col]==0&&uppdiag[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowdiag[row+col]=1;
                uppdiag[n-1+col-row]=1;
                solve(col+1,board,ans,leftrow,uppdiag,lowdiag,n);
                board[row][col]='.';
                leftrow[row]=0;
                lowdiag[row+col]=0;
                uppdiag[n-1+col-row]=0;
            }
        }
        return;
    }
    vector<vector<int>>nQueen(int n){
        vector<vector<int>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0),uppdiag(2*n-1,0),lowdiag(2*n-1,0);
        solve(0,board,ans,leftrow,uppdiag,lowdiag,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends