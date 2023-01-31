//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            m[s[j]]++;
            int ct=0;
            for(auto &it:m){
                ct=max(ct,it.second);
            }
            if((j-i+1)-ct<=k){
                ans=max(ans,(j-i+1));
            }
            if((j-i+1)-ct>k){
                while((j-i+1)-ct>k){
                    m[s[i]]--;
                    i++;
                    for(auto &it:m){
                        ct=max(ct,it.second);
                    }
                }
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends