//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    // write code here
    int mod=1e9+7;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int count=0;
            if(i-1>0 && j-2>0) count++;
            if(i-1>0 && j+2<=m) count++;
            if(i-2>0 && j-1>0) count++;
            if(i-2>0 && j+1<=m) count++;
            if(i+1<=n && j-2>0) count++;
            if(i+1<=n && j+2<=m) count++;
            if(i+2<=n && j-1>0) count++;
            if(i+2<=n && j+1<=m) count++;
            ans+=(n*m-count-1);
            ans%=mod;
        }
    }
    return ans;
}