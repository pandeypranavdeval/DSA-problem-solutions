//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void solve(int ind,string s,string op,map<string,int>&m,vector<string>&ans){
        if(ind==s.size()){
            ans.push_back(op);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string temp=s.substr(ind,i-ind+1);
            if(m[temp]>0){
                if(op.size()==0){
                    //op=temp;
                    solve(i+1,s,op+temp,m,ans);
                }
                else{
                    // temp=" "+temp;
                    // op+=temp;
                    solve(i+1,s,op+" "+temp,m,ans);
                }
                //solve(i+1,s,op,m,ans);
                //op.erase(op.find(temp),temp.size());
            }
        }
        return;
    }
    
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s){
        vector<string>ans;
        map<string,int>m;
        for(int i=0;i<dict.size();i++){
            m[dict[i]]++;
        }
        string op;
        solve(0,s,op,m,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends