//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void solve(string s,string k,vector<string>&ans){
        if(s.size()==0){
            ans.push_back(k);
            return ;
        }
        string op1=k;
        string op2=k;
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,op1,ans);
        solve(s,op2,ans);
        return ;
    }
    vector<string> permutation(string s){
        vector<string>ans;
        string k;
        k.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,k,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends