//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        string ans;
        int p1=0,p2=1;
        int lo,hi;
        for(int i=1;i<s.size();i++){
            lo=i-1;
            hi=i;
            while(lo>=0&&hi<s.size()&&s[lo]==s[hi]){
                if(hi-lo+1>p2){
                    p1=lo;
                    p2=hi-lo+1;
                }
                
                lo--;
                hi++;
            }
        //odsubs
            lo=i-1;
            hi=i+1;
            while(lo>=0&&hi<s.size()&&s[lo]==s[hi]){
                if(hi-lo+1>p2){
                    p1=lo;
                    p2=hi-lo+1;
                }
                lo--;
                hi++;
            }
        }
        for(int i=p1;i<=(p1+p2-1);i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends