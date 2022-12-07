//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &ast) {
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ast[i]>0){
                s.push(ast[i]);
            }
            else{
                int x=-ast[i];
                while(!s.empty()&&s.top()>0&&s.top()<x){
                    s.pop();
                }
                if(!s.empty()&&s.top()==x){
                    s.pop();
                }
                else if(!s.empty()&&s.top()>x){

                }
                else{
                    s.push(ast[i]);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends