//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        int ans=0;
        int a[k]={0};
        for(int i=0;i<n;i++){
            a[arr[i]%k]++;
        }
        int p=1,q=k-1;
        while(p<q){
            ans+=max(a[p],a[q]);
            p++;
            q--;
        }
        if(p==q&&a[p]>0){
            ans++;
        }
        if(a[0]>0){
            ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends