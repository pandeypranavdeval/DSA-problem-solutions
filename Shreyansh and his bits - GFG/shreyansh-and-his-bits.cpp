//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
const int kn=40;
long long cache[kn][kn];
class Solution{
public:
    long long ncr(long long n,long long r){
        if(r>n){
            return 0;
        }
        if(r==0||r==n){
            return 1;
        }
        if(cache[n][r]!=-1){
            return cache[n][r];
        }
        auto res=ncr(n-1,r-1)+ncr(n-1,r);
        return cache[n][r]=res;
    }
    long long count(long long n) {
        for(int i=0;i<kn;i++){
            for(int j=0;j<kn;j++){
                cache[i][j]=-1;
            }
        }
        long long ans=0;
        long long int ct=0;
        long long pos=0;
        while(n>0){
            if((n&1)==1){
                ct++;
                ans+=ncr(pos,ct);
            }
            n=n>>1;
            pos++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends