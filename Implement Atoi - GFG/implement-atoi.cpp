//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        bool flag=false;
        if(s[0]=='-'){
            flag=true;
            
        }
        int i=0;
        if(flag){
            i++;
        }
        for(;i<s.size();i++){
            if((s[i]-'0')>=0&&(s[i]-'0')<=9){
                ans=ans*10+((s[i]-'0'));
            }
            else{
                return -1;
            }
        }
        if(flag){
            return ans*-1;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends