//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string isSumOfTwo(int n){
        const int N=1e5+2;
        vector<bool>isprime(N,1);
        //bool isprime[1e5+2]={1};
        isprime[0]=isprime[1]=false;
        for(int i=2;i<N;i++){
            if(isprime[i]==true){
                for(int j=2*i;j<N;j+=i){
                    isprime[j]=false;
                }   
            }
        }
        for(int i=1;i<n;i++){
            if(isprime[i]==true){
                if(isprime[n-i]==true){
                    return "Yes";
                }
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends