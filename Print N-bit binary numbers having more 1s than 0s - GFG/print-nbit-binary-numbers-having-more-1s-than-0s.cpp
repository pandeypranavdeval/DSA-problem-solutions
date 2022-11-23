//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void recfun(int zc,int oc,int n,string k,vector<string>&ans){
        if(n==0){
            ans.push_back(k);
            return;
        }
        string op1=k;
        op1.push_back('1');
        recfun(zc,oc+1,n-1,op1,ans);
        if(oc>zc){
            string op2=k;
            op2.push_back('0');
            recfun(zc+1,oc,n-1,op2,ans);
        }
        return ;
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    int zc=0;
	    int oc=0;
	    string k="";
	    recfun(zc,oc,n,k,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends