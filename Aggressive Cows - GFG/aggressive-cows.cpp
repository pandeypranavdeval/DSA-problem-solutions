//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool pred(vector<int> &stalls,int &n,int k,long long &mid){
        int lastpos=-1;
        for(int i=0;i<n;i++){
            if(stalls[i]-lastpos>=mid||lastpos==-1){
                k--;
                lastpos=stalls[i];
            }
            if(k==0){
                break;
            }
        }
        return k==0;
    }
    int solve(int n, int k, vector<int> &stalls) {
        int lo=0;
        int hi=1e9;
        int ans=0;
        sort(stalls.begin(),stalls.end());
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(pred(stalls,n,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends