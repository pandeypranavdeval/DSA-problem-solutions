//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
	string printMinIndexChar(string s, string p)
	{
	    map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==0){
                m[s[i]]=(i+1);
            }
        }
        string ans;
        int ind=s.size()+1;
        for(int i=0;i<p.size();i++){
            if(m[p[i]]>0&&m[p[i]]<ind){
                ans.clear();
                ans.push_back(p[i]);
                ind=m[p[i]];
            }
        }
        if(ans.size()==0){
            ans="$";
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string str;
        cin>>str;
        string patt;
        cin >> patt;
        Solution obj;
        cout<<obj.printMinIndexChar(str, patt)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends