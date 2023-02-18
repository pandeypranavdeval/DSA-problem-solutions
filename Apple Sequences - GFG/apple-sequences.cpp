//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int i=0;
        int j=0;
        int ct=0;
        int ans=0;
        while(j<arr.size()){
            if(arr[j]=='O'){
                ct++;
            }
            if(ct<=m){
                ans=max(ans,(j-i+1));
            }
            else{
                while(ct>m){
                    if(arr[i]=='O'){
                        ct--;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends