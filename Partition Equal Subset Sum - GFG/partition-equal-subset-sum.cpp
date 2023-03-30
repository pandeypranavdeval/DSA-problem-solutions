//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int nums[])
    {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1){
            return false;
        }
        else{
            sum=sum/2;
            bool dp[n+1][sum+1];
            for(int j=0;j<sum+1;j++){
                dp[0][j]=false;
            }
            for(int i=0;i<n+1;i++){
                dp[i][0]=true;
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends