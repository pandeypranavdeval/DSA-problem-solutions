//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int n, vector<char>&tasks) {
        unordered_map<char,int>m;
        priority_queue<int>maxh;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto&it:m){
            maxh.push(it.second);
        }
        int ideal=(maxh.top()-1)*n;
        int hf=maxh.top();
        maxh.pop();
        while(!maxh.empty()){
            ideal-=min(hf-1,maxh.top());
            maxh.pop();
        }
        return tasks.size()+max(0,ideal);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends