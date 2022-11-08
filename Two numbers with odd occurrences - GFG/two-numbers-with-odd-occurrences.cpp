//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int k=0;
        for(int i=0;i<N;i++){
            k=(k^Arr[i]);
        }
        int p=0;
        for(int i=0;i<64;i++){
            if((k&(1<<i))!=0){
                p=i;
                break;
            }
        }
        long long int a=0,b=0;
        for(int i=0;i<N;i++){
            if((Arr[i]&(1<<p))!=0){
                a=(a^Arr[i]);
            }
            else{
                b=(b^Arr[i]);
            }
        }
        vector<long long int >ans;
        ans.push_back(a);
        ans.push_back(b);
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends