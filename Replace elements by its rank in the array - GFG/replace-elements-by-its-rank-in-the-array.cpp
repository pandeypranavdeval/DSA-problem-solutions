//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int>&arr, int n){
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]=0;
        }
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
        }
        int ct=1;
        while(!minh.empty()){
            int ele=minh.top();
            minh.pop();
            if(!minh.empty()){
                if(ele==minh.top()){
                    m[ele]=ct;
                }
                else{
                    m[ele]=ct++;
                }
            }
            else{
                m[ele]=ct;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends