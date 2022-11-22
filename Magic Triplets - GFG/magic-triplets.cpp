//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>arr){
	    int ans=0;
	    int n=arr.size();
	    for(int j=1;j<n;j++){
	        int sm=0;
	        for(int i=j;i>=0;i--){
	            if(arr[i]<arr[j]){
	                sm++;
	            }
	        }
	        int gt=0;
	        for(int k=j;k<n;k++){
	            if(arr[k]>arr[j]){
	                gt++;
	            }
	        }
	        ans+=gt*sm;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends