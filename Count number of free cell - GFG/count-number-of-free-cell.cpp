//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int> ans;
      long long int val=n*1LL*n;
      unordered_map<int,int>r;
      unordered_map<int,int>c;
      int ctr=0,ctc=0;
      for(int i=0;i<k;i++){
          long long t=0;
          if(r[arr[i][0]]==0){
              r[arr[i][0]]=1;
              ctr++;
              t+=n-ctc;
          }
          if(c[arr[i][1]]==0){
              c[arr[i][1]]=1;
              ctc++;
              t+=n-ctr;
          }
          val-=t;
          ans.push_back(val);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends