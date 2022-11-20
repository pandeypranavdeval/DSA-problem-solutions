//{ Driver Code Starts
#include<bits/stdc++.h>
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
	        op2.push_back(s[0]);
	        s.erase(s.begin()+0);
	        solve(s,op1,ans);
	        solve(s,op2,ans);
	        return ;
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    string k="";
		    solve(s,k,ans);
		    
		    sort(ans.begin(),ans.end());
		    ans.erase(ans.begin()+0);
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends