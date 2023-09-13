//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        string ans;
        int n1=n;
        if(s==0){
            if(n==1){
                return "0";
            }
            else{
                return "-1";
            }
        }
        while(s){
            if(s>9){
                ans.push_back((9+'0'));
                s-=9;
                n--;
            }
            else{
                ans.push_back((s+'0'));
                s=0;
                n--;
            }
        }
        if(n<0){
            return "-1";
        }
        while(n--){
            ans.push_back('0');
        }
        //cout<<ans<<" ";
        if(ans.size()==n1){
            return ans;
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends