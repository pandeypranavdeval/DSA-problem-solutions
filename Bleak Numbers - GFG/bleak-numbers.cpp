//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
int countSetBit(int x){
        int count=0;
        while(x){
            x = x&(x-1);
            count++;
        }
        return count;
    }
 
 
int is_bleak(int n)
{
    // Code here.
   int ans=0;
    for(int i= 0; i<=31;i++){
        ans =0;
       if(n-i >0) ans = (n-i)+countSetBit(n-i);
        if(ans == n) return 0;
    }
return 1;
}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends