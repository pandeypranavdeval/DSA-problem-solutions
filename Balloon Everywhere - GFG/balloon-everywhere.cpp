//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        string b="balloon";
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<b.size();i++){
            m1[b[i]]++;
            m2[b[i]]=0;
        }
        for(int i=0;i<s.size();i++){
            if(m2.find(s[i])!=m2.end()){
                m2[s[i]]++;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<b.size();i++){
            ans=min(ans,m2[b[i]]/m1[b[i]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends