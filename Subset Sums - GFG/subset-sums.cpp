//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>arr,int N,vector<int>op,vector<int>&ans){
        if(N==0){
            int k=accumulate(op.begin(),op.end(),0);
            ans.push_back(k);
            return ;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(arr[0]);
        arr.erase(arr.begin()+0);
        solve(arr,N-1,op1,ans);
        solve(arr,N-1,op2,ans);
        return ;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        vector<int>op;
        solve(arr,N,op,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends