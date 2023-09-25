//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &v1, vector<int> &v2) {
        vector<int> ans;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({v1[n-1]+v2[n-1],{n-1,n-1}});
        set<pair<int,int>>s;
        s.insert({n-1,n-1});
        while(k--){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.first);
            int x=it.second.first;
            int y=it.second.second;
            if(s.find({x-1,y})==s.end()){
                pq.push({v1[x-1]+v2[y],{x-1,y}});
                s.insert({x-1,y});
            }
            if(s.find({x,y-1})==s.end()){
                pq.push({v1[x]+v2[y-1],{x,y-1}});
                s.insert({x,y-1});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends