//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i=0;
        vector<int>ans(2);
        int j=n-1;
        int v=INT_MAX;
        while(i<m&&j>=0){
            if((arr[j]+brr[i])==x){
                ans[0]=arr[j];
                ans[1]=brr[i];
                brr[i];
                break;
            }
            else if((arr[j]+brr[i])>x){
                if(v>abs((arr[j]+brr[i])-x)){
                    v=abs((arr[j]+brr[i])-x);
                    ans[0]=arr[j];
                    ans[1]=brr[i];
                }
                j--;
            }
            else{
                if(v>abs((arr[j]+brr[i])-x)){
                    v=abs((arr[j]+brr[i])-x);
                    ans[0]=arr[j];
                    ans[1]=brr[i];
                }
                i++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends