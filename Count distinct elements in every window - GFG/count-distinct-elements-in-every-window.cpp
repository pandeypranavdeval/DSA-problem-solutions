//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        int i=0,j=0;
        vector <int>ans;
        map<int,int>m;
        while(j<n){
            m[A[j]]++;
            if(j>=k-1){
                ans.push_back(m.size());
                m[A[i]]--;
                if(m[A[i]]==0){
                    m.erase(A[i]);
                }
                i++;
            }
            j++;
        }
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends