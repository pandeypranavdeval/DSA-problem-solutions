//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums){
	    int n=nums.size();
	    vector<int>inc(n,1);
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j]){
	                inc[i]=max(inc[i],1+inc[j]);
	            }
	        }
	    }
	    vector<int>dec(n,1);
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[i]>nums[j]){
	               dec[i]=max(dec[i],1+dec[j]);
	            }
	        }
	    }
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,(inc[i]+dec[i]-1));
	    }
	    return maxi;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends