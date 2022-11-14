//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int ans=0;
        vector<bool>vis(s.size(),false);
        for(int i=0;i<s.size();i++){
            if(s[i]==w[0]&&!vis[i]){
                vis[i]=true;
                int j=i+1;
                int k=1;
                while(j<s.size()&&k<w.size()){
                    if(s[j]==w[k]&&!vis[j]){
                        vis[j]=true;
                        k++;
                    }
                    j++;
                }
                if(k==w.size()){
                    ans++;
                }
                else{
                    break;
                }
            }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends