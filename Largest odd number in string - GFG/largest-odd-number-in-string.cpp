//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string num) {
        // your code here
        string ans;
        int l=-1;
        for(int i=num.size()-1;i>=0;i--){
            int k=num[i]-'0';
            if(k&1){
                l=i;
                break;
            }
        }
        for(int i=0;i<=l;i++){
            ans.push_back(num[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends