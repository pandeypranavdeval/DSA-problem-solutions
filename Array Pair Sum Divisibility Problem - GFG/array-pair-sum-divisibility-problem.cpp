//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
         map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]%k]++;
        }
        for(auto it:m){
            if(it.first==0){
                if(it.second%2)
                return false;
            }
         else if(m[k-it.first]!=m[it.first])
          return false;
        }
        return true;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends