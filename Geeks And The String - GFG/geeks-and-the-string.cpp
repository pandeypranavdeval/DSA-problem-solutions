//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        string ans;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            ans="-1";
        }
        else{
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends