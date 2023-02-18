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
        map<char,int>mp;
        int ans=0;
        while(j<arr.size()){
            if(arr[j]=='O'){
                mp[arr[j]]++;
            }
            //cout<<mp['O']<<" ";
            if(mp['O']<=m){
                ans=max(ans,(j-i+1));
                //cout<<ans<<" ";
            }
            else{
                while(mp['O']>m&&i<arr.size()){
                    if(arr[i]=='O'){
                        mp[arr[i]]--;
                    }
                    i++;
                    ans=max(ans,(j-i+1));
                }
            }
            j++;
        }
        //cout<<"\n";
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