//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int leftoc(int arr[],int n,int x){
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==x){
                ans=mid;
                hi=mid-1;
            }
            else if(arr[mid]>x){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    int rightoc(int arr[],int n,int x){
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==x){
                ans=mid;
                lo=mid+1;
            }
            else if(arr[mid]>x){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans(2,-1);
        int lo=leftoc(arr,n,x);
        int ro=rightoc(arr,n,x);
        if((lo!=-1)&&(ro!=-1)){
            ans[0]=lo;
            ans[1]=ro;
            return ans;
        }
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
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends